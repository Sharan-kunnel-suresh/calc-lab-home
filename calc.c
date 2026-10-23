// Sharan Kunnel Suresh 251ADB024
// https://github.com/Sharan-kunnel-suresh/calc-lab-home
// Compile with: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm
// Resources used: 
// AI (OpenAI ChatGPT, GPT-6): Prompt: "Explain how to
// implement a recursive-descent parser in C with operator
// precedence and exact error positions."
// Conversation history: [PASTE YOUR CHATGPT SHARE LINK HERE]
// I used this explanation to understand the parser design;
// I implemented and tested the code in this section myself.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    const char *text;
    size_t pos;
    size_t end;
    size_t error_pos;
    size_t line_end_pos;
    long long value;
} Parser;

static void skip_spaces(Parser *p)
{
    while (p->pos < p->end &&
           (p->text[p->pos] == ' ' ||
            p->text[p->pos] == '\t' ||
            p->text[p->pos] == '\r')) {
        p->pos++;
    }
}

static int parse_number(Parser *p, long long *result)
{
    skip_spaces(p);

    if (p->pos >= p->end ||
        !isdigit((unsigned char)p->text[p->pos])) {
        p->error_pos = p->pos < p->end
                       ? p->pos + 1
                       : p->line_end_pos;
        return 0;
    }

    long long number = 0;

    while (p->pos < p->end &&
           isdigit((unsigned char)p->text[p->pos])) {
        number = number * 10 + (p->text[p->pos] - '0');
        p->pos++;
    }

    *result = number;
    return 1;
}

/* Addition and subtraction are processed left to right. */
static int parse_expression(Parser *p, long long *result)
{
    long long value;

    if (!parse_number(p, &value)) {
        return 0;
    }

    for (;;) {
        skip_spaces(p);

        if (p->pos >= p->end) {
            *result = value;
            return 1;
        }

        char op = p->text[p->pos];

        if (op != '+' && op != '-') {
            p->error_pos = p->pos + 1;
            return 0;
        }

        p->pos++;

        long long right;
        if (!parse_number(p, &right)) {
            return 0;
        }

        if (op == '+') {
            value += right;
        } else {
            value -= right;
        }
    }
}

static int evaluate_line(const char *text,
                         size_t start,
                         size_t end,
                         size_t line_end_pos,
                         long long *result,
                         size_t *error_pos)
{
    Parser p = {text, start, end, 0, line_end_pos, 0};

    skip_spaces(&p);

    if (p.pos == p.end ||
        text[p.pos] == '#') {
        return 2; /* Blank or comment line. */
    }

    if (!parse_expression(&p, result)) {
        *error_pos = p.error_pos;
        return 0;
    }

    return 1;
}

static char *read_file(FILE *file, size_t *length)
{
    size_t capacity = 4096;
    size_t used = 0;
    char *buffer = malloc(capacity);

    if (buffer == NULL) {
        return NULL;
    }

    for (;;) {
        if (used == capacity) {
            if (capacity > (size_t)-1 / 2) {
                free(buffer);
                return NULL;
            }

            size_t new_capacity = capacity * 2;
            char *new_buffer = realloc(buffer, new_capacity);

            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }

            buffer = new_buffer;
            capacity = new_capacity;
        }

        size_t count = fread(buffer + used, 1, capacity - used, file);
        used += count;

        if (count == 0) {
            if (ferror(file)) {
                free(buffer);
                return NULL;
            }
            break;
        }
    }

    *length = used;
    return buffer;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: calc input.txt\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        fprintf(stderr, "Cannot open input file\n");
        return 1;
    }

    size_t length;
    char *text = read_file(file, &length);
    fclose(file);

    if (text == NULL) {
        fprintf(stderr, "Cannot read input file\n");
        return 1;
    }

    size_t start = 0;

    while (start < length) {
        size_t end = start;

        while (end < length && text[end] != '\n') {
            end++;
        }

        size_t line_end_pos = end + 1;
        size_t content_end = end;

        if (content_end > start &&
            text[content_end - 1] == '\r') {
            content_end--;
        }

        long long result;
        size_t error_pos = 0;

        int status = evaluate_line(
            text, start, content_end, line_end_pos,
            &result, &error_pos
        );

        if (status == 0) {
            printf("ERROR:%zu\n", error_pos);
            free(text);
            return 0;
        }

        if (status == 1) {
            printf("%lld\n", result);
        }

        start = end < length ? end + 1 : end;
    }

    free(text);
    return 0;
}
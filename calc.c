// Sharan Kunnel Suresh 251ADB024
// https://github.com/Sharan-kunnel-suresh/calc-lab-home
// Compile with: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm
// Resources used: 
// AI (OpenAI ChatGPT, GPT-6): Prompt: 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>
// Used chat gpt to research structure that is need ed to do float 
typedef struct{
    long long integer;
    double floating;
    int is_float;

}Value;
typedef struct {
    const char *s;
    size_t pos, end, line_end;
    size_t error;
} Parser;

static void s_skipper(Parser *p){
    while (p->pos < p->end &&
           (p->text[p->pos] == ' ' ||
            p->text[p->pos] == '\t' ||
            p->text[p->pos] == '\r')) {
        p->pos++;
    }
}


static Value int_value(long long x){
    Value v;
    v.i=x;
    v.is_float=0;
    return v;
}
static Value int_value(long long x){
    Value v;
    v.i=x;
    v.d=(double)x;
    v.is_float=0;
    return v;
}
// referred Chatgpt for this code snippet 
static Value float_value(double x)
{
    Value v;
    v.i = 0;
    v.d = x;
    v.is_float = 1;
    return v;
}

static int fail_at(Parser *p, size_t pos)
{
    p->error = pos;
    return 0;
}

static int parse_expr(Parser *p, Value *out);
// till here  
static int number_parser(Parser *p, Value *out)
{
    size_t start;
    int before = 0, after = 0;
    long long integer = 0;
    double number = 0.0;
    double fraction_scale = 0.1;
    s_skipper(p);

    start = p->pos;

    if (p->pos >= p->end)
        return fail_at(p, p->line_end);

    if (!isdigit((unsigned char)p->s[p->pos])) {
        return fail_at(p, p->pos + 1);
    }

    while (p->pos < p->end &&
           isdigit((unsigned char)p->s[p->pos])) {
        int digit = p->s[p->pos] - '0';
        before = 1;
        number = number * 10.0 + (double)digit;
        integer = integer * 10 + digit;
        p->pos++;
    }

    if (p->pos < p->end && p->s[p->pos] == '.') {
        p->pos++;
        while (p->pos < p->end &&
               isdigit((unsigned char)p->s[p->pos])) {
            int digit = p->s[p->pos] - '0';
            after = 1;
            number += (double)digit * fraction_scale;
            fraction_scale *= 0.1;
            p->pos++;
        }
        if (!before || !after)
            return fail_at(p, p->pos < p->end ? p->pos : p->line_end);
        if (p->pos < p->end &&
            (p->s[p->pos] == 'e' || p->s[p->pos] == 'E'))
            return fail_at(p, p->pos + 1);
        if (!isfinite(number))
            return fail_at(p, start + 1);
        *out = float_value(number);
        return 1;
}


/*
 * Multiplication and division are grouped in parse_term().
 * This makes them bind more tightly than + and -.
 * This stage uses integer arithmetic; parentheses and powers
 * will be added in later stages.
 */
static int parse_primary(Parser *p, long long *result);
static int parsein_power(Parser *p, long long *result);
static int parse_term(Parser *p, Value *out){
    Value value;

    if (!parsein_power(p, &value)) {
        return 0;
    }

    for (;;) {
        char op;
        size_t op_pos, right_start;
        Value right;
        s_skipper(p);

        if (p->pos >= p->end || p->s[p->pos] == ')' ) {
            *out = value;
            return 1;
        }
        op = p->s[p->pos];
        if (op != '*' && op != '/')
            break;
        if (p->pos + 1 < p->end && op == '*' &&
            p->s[p->pos + 1] == '*')
            break;
        op_pos = p->pos++;
        skip_space(p);
        right_start = p->pos;
        if (!parse_power(p, &right))
            return 0;

        if (op == '/' &&
            ((!right.is_float && right.i == 0) ||
             (right.is_float && right.d == 0.0)))
            return fail_at(p, right_start < p->end ?
                           right_start + 1 : p->line_end);

        if (!value.is_float && !right.is_float) {
            if (op == '*')
                value = int_value(value.i * right.i);
            else
                value = int_value(value.i / right.i);
        } else {
            double a = value.is_float ? value.d : (double)value.i;
            double b = right.is_float ? right.d : (double)right.i;
            double r = op == '*' ? a * b : a / b;
            if (!isfinite(r))
                return fail_at(p, op_pos + 1);
            value = float_value(r);
        }
    }
    *out = value;
    return 1;
}

/*
 * Addition and subtraction call parse_term(), so each multiplication
 * or division is evaluated before the surrounding + or - operation.
 * The loop also preserves left-to-right evaluation at this level.
 */
static int parse_expr(Parser *p, long long *result)
{
    long long value;

    if (!parse_term(p, &value)) {
        return 0;
    }

    for (;;) {
        s_skipper(p);

        if (p->pos >= p->end) {
            *result = value;
            return 1;
        }
        char op = p->text[p->pos];
        if (op == ')') {
            *result = value;
            return 1;
        }

        if (op != '+' && op != '-') {
            p->error_pos = p->pos + 1;
            return 0;
        }

        p->pos++;

        long long right;
        if (!parse_term(p, &right)) {
            return 0;
        }

        if (op == '+') {
            value += right;
        } else {
            value -= right;
        }
    }
}
static int parse_primary(Parser *p, Value *out){
    s_skipper(p);

    if (p->pos >= p->end)
        return fail_at(p, p->line_end);

    if (p->s[p->pos] == '(') {
        p->pos++;
        skip_space(p);
        if (p->pos < p->end && p->s[p->pos] == ')')
            return fail_at(p, p->pos + 1);

        if (!parse_expr(p, out))
            return 0;
        skip_space(p);
        if (p->pos >= p->end)
            return fail_at(p, p->line_end);
        if (p->s[p->pos] != ')')
            return fail_at(p, p->pos + 1);
        p->pos++;
        return 1;
    }
    return parse_number(p, out);
}


//adding the powerr function d
//edited according to use "Value" 
static int parsein_power(Parser *p, Value  *out)
{
    Value base, exponent;
    size_t op_pos;

    if (!parse_primary(p, &base))
        return 0;
    skip_space(p);
    if (p->pos + 1 >= p->end ||
        p->s[p->pos] != '*' || p->s[p->pos + 1] != '*') {
        *out = base;
        return 1;
    }

    op_pos = p->pos;
    p->pos += 2;
    skip_space(p);
    size_t exponent_start = p->pos;

    if (!parsein_power(p, &exponent))
        return 0;

    if (!base.is_float && !exponent.is_float) {
        if (exponent.i < 0)
            return fail_at(p, exponent_start < p->end ?
                           exponent_start + 1 : p->line_end);
        long long result = 1;
        for (long long k = 0; k < exponent.i; k++)
            result *= base.i;
        *out = int_value(result);
        return 1;
    }

    double b = base.is_float ? base.d : (double)base.i;
    double e = exponent.is_float ? exponent.d : (double)exponent.i;
    double result = pow(b, e);
    if (!isfinite(result))
        return fail_at(p, op_pos + 1);
    *out = float_value(result);
    return 1;
}

static int evaluate_line(const char *text,
                         size_t start,
                         size_t end,
                         size_t line_end,Value *result,size_t *error)
{
    Parser p;
    p.s = text;
    p.pos = start;
    p.end = end;
    p.line_end = line_end;
    p.error = 0;

    s_skipper(&p);

    if (p.pos == p.end || p.s[p.pos] == '#')
        return 2;

    if (!parse_expr(&p, result)) {
        *error = p.error;
        return 0;
    }
    s_skipper(&p);

    if (p.pos < p.end) {
        *error = p.pos + 1;
        return 0;
    }

    return 1;
}
//reading file
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
typedef struct{
    char *data;
    size_t len,cap
}Output;
//Used Chatgpt
static int append_text(Output *o, const char *s, size_t n){
    if (n>(size_t)-1 - o->len - 1)
        return 0;
    size_t need =o->len + n + 1;
    if (need > o->cap) {
        size_t cap = o->cap ? o->cap : 256;
        while (cap < need) {
            if (cap > (size_t)-1 / 2)
                return 0;
            cap *= 2;
        }
        char *tmp = realloc(o->data, cap);
        if (!tmp)
            return 0;
        o->data = tmp;
        o->cap = cap;
    }
    memcpy(o->data + o->len, s, n);
    o->len += n;
    o->data[o->len] = '\0';
    return 1
}
static int append_result(Output *o, Value v){
    char buf[128];
    int n;
    if (v.is_float)
        n = snprintf(buf, sizeof buf, "%.15g\n", v.d);
    else
        n = snprintf(buf, sizeof buf, "%lld\n", v.i);
    return n >= 0 && (size_t)n < sizeof buf &&
           append_text(o, buf, (size_t)n);
}
//used chatgpt
static int process_input(const char *path, const char *outpath)
{
    FILE *in = fopen(path, "rb");
    if (!in) {
        fprintf(stderr, "Cannot open input file: %s\n", path);
        return 0;
    }
    size_t length = 0;
    char *text = read_file(in, &length);
    fclose(in);
    if (!text) {
        fprintf(stderr, "Cannot read input file: %s\n", path);
        return 0;
    }

    Output output = {NULL, 0, 0};
    size_t start = 0;
    size_t global_error = 0;
    while (start < length) {
        size_t end = start;
        while (end < length && text[end] != '\n')
            end++;
        size_t line_end = end + 1;
        size_t content_end = end;
        if (content_end > start && text[content_end - 1] == '\r')
            content_end--;

        Value v;
        size_t error = 0;
        int status = evaluate_line(text, start, content_end,
                                   line_end, &v, &error);
        if (status == 0) {
            global_error = error;
            break;
        }
        if (status == 1 && !append_result(&output, v)) {
            fprintf(stderr, "Out of memory while storing results\n");
            free(output.data);
            free(text);
            return 0;
        }
        start = end < length ? end + 1 : end;
    }

    if (global_error) {
        char errbuf[64];
        int n = snprintf(errbuf, sizeof errbuf, "ERROR:%zu\n", global_error);
        output.len = 0;
        if (n < 0 || (size_t)n >= sizeof errbuf ||
            !append_text(&output, errbuf, (size_t)n)) {
            free(output.data);
            free(text);
            fprintf(stderr, "Out of memory while storing error\n");
            return 0;
        }
    }

    FILE *out = fopen(outpath, "wb");
    if (!out) {
        fprintf(stderr, "Cannot write output file: %s\n", outpath);
        free(output.data);
        free(text);
        return 0;
    }
    int ok = output.len == 0 ||
             fwrite(output.data, 1, output.len, out) == output.len;
    if (fclose(out) != 0)
        ok = 0;
    if (!ok)
        fprintf(stderr, "Failed writing output file: %s\n", outpath);

    free(output.data);
    free(text);
    return ok;
}
# calc-lab-home
Writing  a C program calc that reads arithmetic expressions from text files, evaluates them, and writes each result, or the exact position of the first error, to an output file.

<div class="no-overflow" id="yui_3_18_1_1_1792575690322_134"><div style="max-width: 900px; line-height: 1.5; color: #1d2125;" id="yui_3_18_1_1_1792575690322_133">
<h2 style="margin: 0 0 12px 0;">Graded lab: Arithmetic Parser in C</h2>
<table style="border-collapse: collapse; margin: 8px 0 16px 0;">
<tbody>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Time</th>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">1 week</td>
</tr>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">You write</th>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">the whole program in one file, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code></td>
</tr>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">You submit</th>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">a link to your last commit in your GitHub repository (see <a href="#calc-submit">9. Submit</a>)</td>
</tr>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">AI tools</th>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">allowed, <strong>if you cite them</strong> (see <a href="#calc-ai">7. Resources and AI</a>)</td>
</tr>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Sample tests</th>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>calc-tests.zip</strong> (attached below): example inputs with expected outputs and two test scripts</td>
</tr>
</tbody>
</table>
<p>Write a C program <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc</code> that reads arithmetic expressions from text files, evaluates them, and writes each result, or the exact position of the first error, to an output file.</p>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">1. Set up your repository</h3>
<ol>
<li>On GitHub, create a new repository.</li>
<li>Work in a Codespace (<strong>Code</strong> → <strong>Codespaces</strong> → <strong>Create codespace on main</strong>).</li>
<li>Your program goes in <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code> in the top folder of the repository. Only <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code> is graded. You may keep other files there too, for example the test files or a Makefile.</li>
</ol>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">2. Building</h3>
<p>Your program is built and graded with exactly this command:</p>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm</pre>
<p>For grade 10 it must also build without warnings and run without errors when built with:</p>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">gcc -O1 -g -Wall -Wextra -std=c17 -fsanitize=address,undefined -o calc calc.c -lm</pre>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">3. File header</h3>
<p>The first lines of <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code> must be:</p>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;" id="yui_3_18_1_1_1792575690322_132">// Name Lastname StudentID
// (optional) <a href="https://github.com/&lt;your-username&gt;/calc-lab-home" class="_blanktarget">https://github.com/&lt;your-username&gt;/calc-lab-home</a>
// Compile with: gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm
// Resources used: &lt;every AI tool, website and book you used; details in comments where you used them&gt;</pre>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">4. The program</h3>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">calc [-d DIR | --dir DIR] [-o OUTDIR | --output-dir OUTDIR] [input.txt]</pre>
<ul>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc -o OUTDIR input.txt</code> evaluates one file.</li>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc -d DIR -o OUTDIR</code> evaluates every <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">*.txt</code> file <strong>directly</strong> inside <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">DIR</code>. Other files and subfolders are ignored.</li>
<li>If <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">OUTDIR</code> does not exist, create it (its parent folder exists). If it already exists, write into it.</li>
<li>Without <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-o</code>, use the default output folder <strong><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">&lt;input_base&gt;_&lt;name&gt;_&lt;studentid&gt;</code></strong> in the current folder. <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">&lt;input_base&gt;</code> is the input file name without <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">.txt</code> or, with <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-d</code>, the folder's name.</li>
<li>For an input <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">task1.txt</code> the output file is <strong><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">&lt;OUTDIR&gt;/task1_&lt;name&gt;_&lt;lastname&gt;_&lt;studentid&gt;.txt</code></strong>.</li>
</ul>
<p>Examples, for the student Anna Berzina with ID 221234:</p>
<table style="border-collapse: collapse; margin: 8px 0 12px 0;">
<tbody>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Command</th>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Writes</th>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc -o results labs/task1.txt</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">results/task1_anna_berzina_221234.txt</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc labs/task1.txt</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">task1_anna_221234/task1_anna_berzina_221234.txt</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc -d labs -o results</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">results/task1_anna_berzina_221234.txt</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">results/task2_anna_berzina_221234.txt</code>, …</td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc -d labs</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">labs_anna_221234/task1_anna_berzina_221234.txt</code>, …</td>
</tr>
</tbody>
</table>
<p><strong>Exit code and messages</strong></p>
<ul>
<li>A file that evaluates to <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:&lt;pos&gt;</code> is a normal result: exit code <strong>0</strong>.</li>
<li>On a missing input file or folder, no arguments, an unknown option, or an output that cannot be written: print a message to <strong>stderr</strong> and exit with a <strong>non-zero</strong> code.</li>
</ul>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">5. Rules</h3>
<p>These rules decide every expected output, and the grading tests check them exactly.</p>
<h4 style="margin: 18px 0 6px 0;">Lines and output</h4>
<ol>
<li>Every non-blank line is one expression. The output file contains one result per expression, in order, one per line. Blank lines produce no output.</li>
<li>A line whose first non-blank character is <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">#</code> is a comment and is ignored. A <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">#</code> anywhere else is an invalid character.</li>
<li>If any error occurs anywhere in the file, the output file contains <strong>only</strong> <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:&lt;pos&gt;</code> for the first error, with no partial results.</li>
</ol>
<h4 style="margin: 18px 0 6px 0;">Positions</h4>
<ol start="4">
<li>Positions are 1-based and count every character in the file, including each <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">\n</code> and the characters in comment lines.</li>
<li>The error position is the start of the token the parser was looking at when it could not continue:</li>
</ol>
<table style="border-collapse: collapse; margin: 8px 0 12px 0;">
<tbody>
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Error</th>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Reported at</th>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Input</th>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Output</th>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">invalid character</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">that character</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 + &amp; 5</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:5</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">two operators in a row</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">the second operator</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">7 + * 3</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:5</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">missing operand at end of line</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">the line's <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">\n</code> (file length + 1 if the last line has no <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">\n</code>)</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">3 * </code> followed by <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">\n</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:5</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">missing <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">)</code> at end of line</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">same as above</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">(2 + 3</code> followed by <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">\n</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:7</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">extra <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">)</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">that <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">)</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">(1 + 2))</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:8</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">division by zero</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">start of the right operand</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">10 / 0</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:6</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">negative integer exponent</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">start of the exponent</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 ** (1 - 2)</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:6</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">float result is infinite or not a number</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">the operator</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">10.0 ** 400</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:6</code></td>
</tr>
</tbody>
</table>
<h4 style="margin: 18px 0 6px 0;">Numbers and operators</h4>
<ol start="6">
<li>Operators, from highest to lowest precedence:
<ul>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">**</code>, right-associative: <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 ** 3 ** 2 == 2 ** 9 == 512</code></li>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">*</code> and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">/</code>, left-associative</li>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">+</code> and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-</code>, left-associative</li>
<li>Parentheses <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">( )</code> group as usual.</li>
</ul>
</li>
<li>There are <strong>no unary operators</strong>: <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-5</code> and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 * -3</code> are errors (at the <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-</code>).</li>
<li><strong>Integers:</strong> digits only, 64-bit (<code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">long long</code>). The tests never overflow.
<ul>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">int / int</code> truncates toward zero like C: <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">7 / 2</code> is <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">3</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">(0 - 7) / 2</code> is <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-3</code>.</li>
<li><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">int ** int</code> with a non-negative exponent is an integer. <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">x ** 0</code> is <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">1</code>, including <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">0 ** 0</code>.</li>
</ul>
</li>
<li><strong>Floats</strong> (grade 10): digits, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">.</code>, digits, for example <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">12.5</code> or <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">0.25</code>. <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">.5</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">5.</code> and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">1.5e3</code> are not valid; the error is at the <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">.</code> or the <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">e</code>.
<ul>
<li>If either operand is a float, the operation is done in <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">double</code>: <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">7 / 2.0</code> is <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">3.5</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">0.5 ** (0 - 1)</code> is <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2</code>.</li>
<li>Float division by zero (<code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">1.5 / 0.0</code>) is a division-by-zero error.</li>
</ul>
</li>
<li><strong>Printing:</strong> integers with <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">%lld</code>, floats with <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">%.15g</code>. So <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">1.25 * 4</code> prints <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">5</code>, and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">0.1 + 0.2</code> prints <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">0.3</code>.</li>
<li>Spaces and tabs may appear anywhere between tokens.</li>
<li>There is no limit on file size or line length: the tests include files of several megabytes. Parentheses nest up to 1000 deep.</li>
</ol>
<h4 style="margin: 18px 0 6px 0;">Constraints</h4>
<ul>
<li>One file, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code>, using only the standard C library (<code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">stdio</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">stdlib</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">string</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ctype</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">math</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">errno</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">dirent</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">sys/stat</code>).</li>
<li>Write your own tokenizer and parser. Do not use flex/bison or call Python, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">bc</code> or any other program.</li>
</ul>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">6. Grading</h3>
<p>Your program is run on a set of test files that follow the rules above. Each grade needs <strong>every</strong> test of that grade and of all grades below it to pass.</p>
<table style="border-collapse: collapse; margin: 8px 0 12px 0;" id="yui_3_18_1_1_1792575690322_138">
<tbody id="yui_3_18_1_1_1792575690322_137">
<tr>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Grade</th>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">You need…</th>
<th style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left; background: #f3f5f7;">Example input → output file</th>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>4</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc -o OUTDIR input.txt</code> with the correct output file name; integers with <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">+</code> and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-</code>; one result per line</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 + 5 - 3</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">4</code><br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 + 2</code> ⏎ <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">10 - 3 + 1</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">4</code> ⏎ <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">8</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>5</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">correct <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:&lt;pos&gt;</code> for invalid characters, operators in a row and missing operands</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">10 + - 3</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:6</code><br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">1 + 2</code> ⏎ <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">3 +</code> (no final <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">\n</code>) → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:10</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>6</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">*</code> and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">/</code> with precedence; division by zero</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">3 + 2 * 5 - 4</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">9</code><br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">5 + 4 / 0 * 2</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:9</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>7</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">parentheses, including missing and extra <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">)</code></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">((2 + 3) * (4 + (6 - 1))) - 10</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">35</code><br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 * ()</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:6</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>8</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">**</code> (right-associative, negative-exponent error); <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">#</code> comment lines and blank lines</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">2 * 3 ** 2 + 1</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">19</code><br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;"># note</code> ⏎ <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">(2 + 3) * 4 # not here</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:20</code></td>
</tr>
<tr>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>9</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">the full command line from section 4: <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">-d</code>/<code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">--dir</code>, <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">--output-dir</code>, default output folder, exit codes and error messages</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">checked by <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">cli.sh</code> in the sample tests</td>
</tr>
<tr id="yui_3_18_1_1_1792575690322_136">
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;"><strong>10</strong></td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;">floats, plus: very large files handled efficiently, no warnings, no sanitizer errors, and good comments</td>
<td style="border: 1px solid #d0d4d9; padding: 5px 9px; vertical-align: top; text-align: left;" id="yui_3_18_1_1_1792575690322_135"><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">3.5 + 2.5 * 2 - 1.0</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">7.5</code><br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">(0 - 8) ** 0.5</code> → <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">ERROR:9</code></td>
</tr>
</tbody>
</table>
<p style="font-size: 0.9em; color: #555;">(⏎ marks a new line in the file.)</p>
<h4 style="margin: 18px 0 6px 0;">Sample tests</h4>
<p>Download <strong>calc-tests.zip</strong>, unpack it next to your <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code> and run:</p>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">gcc -O2 -Wall -Wextra -std=c17 -o calc calc.c -lm
sh calc-tests/run_tests.sh ./calc     # file tests: tests/NAME.txt vs tests/NAME_output.txt
sh calc-tests/cli.sh ./calc           # command-line tests (grade 9)</pre>
<ul>
<li>Test files are named after their grade: <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">g6_zero.txt</code> is a grade 6 test, and <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">g6_zero_output.txt</code> is its expected output.</li>
<li>Grading uses <strong>more tests</strong> than these, including files of several megabytes. All of them follow the rules in section 5. Passing the samples is a good sign, but follow the rules, not just the samples.</li>
</ul>
<h4 style="margin: 18px 0 6px 0;">Can lower your grade</h4>
<ul>
<li>Up to <strong>−1</strong>: crashes, memory errors, undefined behaviour or memory leaks on normal input.</li>
<li>Up to <strong>−2</strong>: missing, unclear or misleading comments, or resources and AI tools used without a citation.</li>
<li>You may be asked to explain any part of your code. If you cannot explain it, the grade can be lowered.</li>
</ul>
<p>Code that does not compile with the command in section 2 cannot be graded.</p>
<h3 id="calc-ai" style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">7. Resources and AI</h3>
<p>You may use books, documentation, websites and AI tools. <strong>Every one must be cited</strong>:</p>
<ol>
<li>On line 4 of <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">calc.c</code>, list every resource and AI tool you used. For AI tools, a conversation history <strong>must</strong> be provided.</li>
<li>At each place in the code where you used one, write a comment saying what you used and, for AI, the prompt:</li>
</ol>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">// Tokenizer structure based on K&amp;R, chapter 5.
// AI (ChatGPT): prompt "how do I read a whole file into memory in C without knowing its size" Link: ...
//   I used the realloc doubling idea; the loop below is my own.</pre>
<p>Relying fully on AI goes against the point of this lab. You are graded on code you understand and can explain.</p>
<h3 style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">8. Comments</h3>
<p>Comments must explain <strong>why</strong>, not what. At least explain:</p>
<ul>
<li>how your tokenizer tracks positions</li>
<li>why your grammar gives the right precedence, and why <code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;">**</code> is right-associative</li>
<li>why each error is reported at the position you chose</li>
<li>how you decide between integer and float arithmetic</li>
<li>how you handle large files without slowing down (no repeated copying)</li>
</ul>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">// Good: power() calls itself for the exponent, so 2**3**2 groups as 2**(3**2).
// Bad:  // call power</pre>
<p><strong>Hint:</strong> a recursive descent parser with one function per precedence level fits these rules well:</p>
<pre style="background: #f3f5f7; color: #1d2125; border: 1px solid #d0d4d9; border-radius: 4px; padding: 10px 12px; overflow-x: auto; font-family: Consolas,Menlo,monospace; font-size: 13px; line-height: 1.45; white-space: pre;">expr    := term  { ('+' | '-') term }
term    := power { ('*' | '/') power }
power   := primary [ '**' power ]
primary := NUMBER | '(' expr ')'</pre>
<h3 id="calc-submit" style="margin: 28px 0 8px 0; padding-bottom: 4px; border-bottom: 2px solid #d0d4d9;">9. Submit</h3>
<p>Commit and push regularly. Your commit history is part of the evidence that the work is your own.</p>
<p>Before the deadline:</p>
<ol>
<li>Push your last commit.</li>
<li>On github.com, open your repository, click the latest commit above the file list, and copy the page address:<br><code style="background: #f3f5f7; color: #1d2125; padding: 1px 4px; border-radius: 3px; font-family: Consolas,Menlo,monospace; font-size: 0.92em;"><a href="https://github.com/&lt;your-username&gt;/calc-lab-home/commit/&lt;long-hash&gt;" class="_blanktarget">https://github.com/&lt;your-username&gt;/calc-lab-home/commit/&lt;long-hash&gt;</a>;</code></li>
<li>Submit that <strong>commit link</strong>.</li>
</ol>
<p>Only the commit you submit is graded.</p>
</div></div>

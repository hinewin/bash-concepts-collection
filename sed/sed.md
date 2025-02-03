## Introduction to sed

`sed` (stream editor) is a powerful text processing utility in Unix-like operating systems. It acts as a filter, accepting input, applying specified changes, and producing modified output.

### Key Features of sed

- Processes multiple lines of input
- Selects and modifies lines based on given instructions
- Outputs a subset of input lines
- Does not modify the input file by default
- Standard output is to the screen

### sed Operation

1. Reads one input line
2. Applies command to line if it matches the address
3. Prints the line (depending on options and instructions)
4. Repeats steps 1-3 for each input line

## sed Formats

### Command Line Format

```bash
sed 'instructions' file_list
```

- Used for short instructions (one or two)
- Instructions are in single quotes
- Multiple instructions separated by semicolons

### Script Format

```bash
sed -f script_name.sed file_list
```

- Used for many instructions or multi-line instructions
- Instructions are in a separate text file (sed script)
- `-f` option tells sed to get instructions from a file

## Important sed Options

### -n Option

```bash
sed -n '/pattern/p' file.txt
```

- Suppresses automatic printing of input lines
- Used when you want to print only specific lines

### -r Option

```bash
sed -r 's/(pattern)/\1_replacement/' file.txt
```

- Enables extended set of regular expressions
- Includes metacharacters like `+`, `{n}`, and `()`

### -i Option

```bash
sed -i 's/old/new/' file.txt
```

- Changes the input file in place
- Use with caution to avoid data loss

## sed Instructions

### Address Field

- Optional part of an instruction
- Selects lines to which the command applies
- Types of addresses:
  - No address (applies to all lines)
  - Single line (e.g., `4d` for line 4)
  - Set of lines (using regex)
  - Range of lines (e.g., `5,8d` for lines 5 through 8)
  - Nested address
  - Not address (using `!`)

### Common sed Commands

1. `=`: Print line numbers
   ```bash
   sed '=' file.txt
   ```
2. `p`: Print matched lines
   ```bash
   sed -n '/pattern/p' file.txt
   ```
3. `q`: Quit processing after a match
   ```bash
   sed '/pattern/q' file.txt
   ```
4. `i`: Insert text before matched lines
   ```bash
   sed '/pattern/i\New line' file.txt
   ```
5. `a`: Append text after matched lines
   ```bash
   sed '/pattern/a\New line' file.txt
   ```
6. `c`: Change (replace) matched lines
   ```bash
   sed '/pattern/c\Replacement line' file.txt
   ```
7. `d`: Delete matched lines
   ```bash
   sed '/pattern/d' file.txt
   ```
8. `s`: Substitute text (replace pattern with new text)
   ```bash
   sed 's/old/new/' file.txt
   ```
9. `y`: Transliterate characters
   ```bash
   sed 'y/abc/ABC/' file.txt
   ```
10. `r`: Read and insert content from a file
    ```bash
    sed '/pattern/r file_to_insert.txt' file.txt
    ```
11. `w`: Write matched lines to a file
    ```bash
    sed -n '/pattern/w output.txt' file.txt
    ```

### Substitute Command (`s`) in Detail

Format: `s/regex/replacement_string/flags`

- Uses standard regex set (use `-r` for extended set)
- Replacement string can include back references:
  - `&` for entire matched string
  - `\num` for specific captured groups

Flags:
- `g`: Global (apply to all matches in the line)
- `p`: Print the modified line
- `w`: Write the modified line to a file

## sed Scripts

- Text files containing multiple sed instructions
- Each instruction on a separate line
- Comments start with `#`
- Use `\` for multi-line instructions
- Group commands with `{ }`

### Running sed Scripts

```bash
sed -f script_name.sed file_list
```

**Note**: The order of instructions in a script can affect the output.

## Best Practices

- Use descriptive names for sed scripts (`.sed` extension optional)
- Be cautious with the `-i` option to avoid data loss
- Use the `-r` option when working with complex regex
- Group multiple commands for one address using `{ }`
- Use comments in scripts for documentation

## Additional Tips

- Test your `sed` commands on a sample file before applying them to important data.
- Use the `-e` option to execute multiple commands from the command line.
- Combine `sed` with other Unix utilities like `grep` and `awk` for more powerful text processing.
- Remember that `sed` processes input line by line, which can affect how you write your instructions.

## Example Exercises

### Exercise 1: Print Line Numbers

```bash
sed '=' module3Ainput
```

### Exercise 2: Add a Line Before Matching Lines

```bash
sed '/line/ i\NEW' module3Ainput
```

### Exercise 3: Substitute and Print Only Changed Lines

```bash
sed -n 's/line/LINE/p' module3Ainput
```

### Exercise 4: Delete Lines with Numbers

```bash
sed '/[0-9]/d' module3Ainput
```

### Exercise 5: Print All Lines Up to a Match

```bash
sed -n '1,/Line/p' module3Ainput
```

These examples are derived from the `module3exerciseSolution` file and demonstrate practical uses of `sed` commands.


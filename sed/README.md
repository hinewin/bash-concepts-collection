## Introduction to sed

`sed` (stream editor) is a powerful text processing utility in Unix-like operating systems. It acts as a filter, accepting input, applying specified changes, and producing modified output.

### Key Features of sed

- Processes multiple lines of input
- Selects and modifies lines based on given instructions
- Outputs a subset of input lines
- Does not modify the input file by default
- Standard output is to the screen

### Instruction to Sed
- Each insruction is made up of two parts
```bash
<Optional Address> <Command>
```
- Address is optional, used to select certain input lines
- Command is required, used to modify the selected lines

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
- **Tip:** Use `-n` with `p` to preview lines that match a pattern before using `d` to delete them. This helps ensure you're targeting the correct lines.

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

- By default `sed` sends output lines to stdout
- Changes the input file in place
- Use with caution to avoid data loss

## sed Instructions

### Instruction Address Field

- **Optional Part of an Instruction**  
  Selects lines to which the command applies.

- **Types of Addresses:**

  - **No Address:**  
    Applies to all lines.
    ```bash
    d  # delete all lines
    ```

  - **Single Line:**  
    Applies to a specific line number.
    ```bash
    4d  # deletes line 4
    ```

  - **Set of Lines:**  
    Uses a regex pattern (surrounded by `/ /`).  
    Command can apply to 0 or multiple lines depending on the match.
    ```bash
    /^[0-9]/d  # delete lines starting with a digit
    ```

  - **Range of Lines:**  
    Format: `start,end`. Each can be a regex or a number.
    ```bash
    5,8d  # deletes lines 5 through 8
    
    /^a/,/^b/d  # delete lines starting from the first line that starts with `a`, stopping after running into a line that starts with `b`
    
    1,/^$/d  # delete from the first line up to and including the first empty line
    ```

  - **Nested Address:**  
    Combines multiple addresses to apply commands to specific lines or ranges.
  - Format: `outer_address { inner_address command } `
    - `outer_address` set or range of lines
    - `inner_address` line number, set of lines or range of lines
    - `command` command to apply to all lines matching both inner and outer address
    ```bash
    5,50 { /^[0-9]/d } # deletes all lines in the range 5 through 50 that start with a digit
    
    /[0-9]/ { / $/d } # For all lines with a digit, delete the linnes that end with a space
    ```

  - **Not Address:**
    - `!` between the address and the command negates the address
    - Similar to `grep -v`
  
    ```bash
    /[0-9]/!d # delete all lines except those with a digit
    ```

### Common sed Commands

1. `=`: Output the line number of each matched line
   - Line number is printed on a seperate line

   ```bash
   /^T/= # Print line number of lines that start with T. 
   # Use -n to print only the matched lines
   ```

1. `p`: Print matched lines
   ```bash
   sed -n '/pattern/p' file.txt
   ```
   ```bash
   /[0-9]/p # Print all lines with a digit
   ```

1. `q`: Quit processing after a match
   ```bash
   sed '/pattern/q' file.txt
   ```
   ```bash
   5q # Quit after the first 5 lines
   # Similar to head -n 5
   ```

1. `i` and `a` Insert and Append text
   - `i` Insert text before matched lines
   - `a` Append text after matched lines
   - Address field can be a single or multiple lines
   - Any text after `i` or `a` and up to the end of the `'` are inserted or appended   
   ```bash
   sed '1i ******' file.txt
   # Insert ***** before line 1
   ```
   ```bash
   sed $a ******* file.txt
   # Append ******* to the end of the file
   ```
   - **WARNING:** To have another command after `i` or `a`, use sed script. 

1. `c` and `d` Commands
   - `c`: Change (replace) matched lines with new text
   - `d`: Delete matched lines

   ```bash
   sed $c ******** # Change the last line of the file to ********
   ```
   - Similar to `a` and `i`, to use another command after `c` or `d`, use sed script.
   ```bash
   /\.$/d # Delete lines that end with a period
   ```

1. `y`: Transliterate each character in the source set into a set of replacement characters
   - Similar to the `tr` utility
   - Source and replacement sets must be the same length
   - Source and replacement sets must be enclosed in `/ /`
   ```bash
   sed 'y/ab/ba/p' file.txt
   # For all lines in the file, substitute all `a` with `b` and all `b` with `a`
   ```

1. `r`: Read and insert content from a file
   - Format: `address r <filename>`
   ```bash
   sed '1r file1.txt' file2.txt
   # For the first line of file2.txt, insert the content of file1.txt
   ```
   ```bash
   sed '$r file1.txt' file2.txt
   # Append file1.txt to the end of file2.txt

1. `w`: Writes the matched input line to a file, overwriting the file if it already exists
   - Format: `address w <filename>`
    ```bash
    sed '/^[a-zA-Z]/w file1.txt' file2.txt
    # For all lines in file2.txt that start with a letter,
    # write the line to file1.txt
    ```

### Substitute Command (`s`) in Detail
`s`: Substitute text (replace pattern with new text)
   - Can use with a flag
   - Typical use with `r` option for extended regex because `s` uses standard regex
   ```bash
   # FORMAT: s/regex/replacement_string/flags
   ```
   **Flags (Optional):**
   - `g`: Global (apply to all matches in the line)
   - `p`: Print the modified line
   - `w`: Write the modified line to a file

   ```bash
   sed -r 's/\/a/b/p' file.txt # Use `\` to escape `/`
   # Substitute `/a` with /b and print the modified line
   ```

   **Back References:**
   - A back reference is a reference to a previously captured group in the regex. In other words, We refer back to the matched string when creating the replacement string.
   - `&` for entire matched string

   ```bash
   sed -r 's/^[0-9][0-9]/+&+/p' file.txt
   # For all lines that start with two digits,
   # replace those 2 digits with a `+` sign, the same 2 digits, and another `+` sign
   ```

   - `\num` for specific captured groups
   - Each part of the regex that is enclosed in `()` is a captured group
   - Remember to use `-r` option
   - Each regex within `()` is stored in sequence in a numbered buffer (like an index)
   ```bash
   sed -r 's/(..)(..)/\2\1/' file.txt
   # For all lines in the file, swap the first 2 characters with the next 2 characters
   # First 2 characters are stored in buffer 1, next 2 characters are stored in buffer 2
   ```
   **`w` flag:**
   - `w` flag writes the modified line to a file
   - Use with `-n` option to suppress automatic printing of input lines
   ```bash
   sed s/[0-9]/*/gw <filename>
   # For all lines that contain a digit, substitute the digit with a `*` 
   # and write the modified line to the file specified by `<filename>`
   ```


## sed Scripts

- Text files containing multiple sed instructions
- Format: `sed -f <script_file.sed> <input_file>`
  - Read in one input line
  - Process all instructions on that one input line
  - If address of the instruction matches, the corresponding command is applied to the line
  - After all instructions are processed with that one line, then the line is sent to screen (depends on the options used)
  - Repeat for each line of input

**Commands Spanning Multiple Lines:**
- If an instruction spans multiple lines, use `\` to escape newlines
- Alternatively use `\n` to represent a newline
```bash
/^T/i 
# First line to be inserted\
# Second line to be inserted

/^T/i \n 
# First line to be inserted\n Second line to be inserted
```

**Multiple Commands for a single address:**
- Group commands with `{ }`
- Within `{ }`, the commands are on separate lines
- Closing `}` must be on a line by itself
```bash
/[0-9]/ { i changing digits to *
          s/[0-9]/*/g
        }
# For all lines that contain a digit,
# insert the text "changing digits to *" before the line,
# substitute all digits with a `*`,
# and print the modified line
```

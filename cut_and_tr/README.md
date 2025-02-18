# Stream Editors in Linux

Stream editors process text streams line by line or character by character, making them efficient for text manipulation without loading entire files into memory.

## tr (translate)

**Purpose**

Character-based translations and transformations

- **Basic Syntax**: `tr [options] set1 set2`
- **Key Options**:
  - `-s` (squeeze): Replaces repeated characters with a single occurrence
  - `-d` (delete): Removes specified characters
  - `-c` (complement): Processes all characters NOT in the specified set

**Key Operations**

- Converting case (upper/lower)
- Replacing single characters
- Deleting specific characters
- Squeezing repeated characters
- Character classes - use for common character groups:
  - `[:alpha:]` - All letters (A-Z, a-z)
  - `[:digit:]` - All numbers (0-9)
  - `[:upper:]` - Uppercase letters (A-Z)
  - `[:alnum:]` - Letters and numbers
  - `[:space:]` - All whitespace (spaces, tabs, newlines)
  - `[:punct:]` - Punctuation characters

**Examples**

```bash
# Basic character replacement
tr 'abc' '123'         # a->1, b->2, c->3

# Case conversion
tr '[:lower:]' '[:upper:]'

# Squeeze Operation (-s)
tr -s ' '              # Multiple spaces to single space
tr -s '\n'             # Multiple newlines to single newline
tr -s ','              # Multiple commas to single comma

# Remove specific characters
tr -d ' '              # Remove all spaces
tr -d '\n'             # Remove all newlines
tr -d '[:digit:]'      # Remove all numbers
```

## The cut Command

The `cut` command is a powerful text processing utility in Unix/Linux systems used for extracting sections from each line of input.

### Basic Syntax

```bash
cut OPTION... [FILE]...
```

### Key Features

- **Field extraction**: Extract specific fields from each line of input.
- **Character extraction**: Extract specific characters or character ranges from each line.
- **Byte extraction**: Extract specific bytes or byte ranges from each line.

### Common Options

- `-f`: Select only these fields.
- `-d`: Use a different delimiter (default is TAB).
- `-c`: Select only these characters.
- `-b`: Select only these bytes.
- `--complement`: Invert the selection.

### Examples

1. Extract the first and third fields from a colon-separated file:

   ```bash
   cut -d: -f1,3 /etc/passwd
   ```

2. Extract characters 1-10 from each line:

   ```bash
   cut -c1-10 filename.txt
   ```

3. Extract all fields except the second:

   ```bash
   cut -d, -f2 --complement data.csv
   ```

4. Use with other commands in a pipeline:

   ```bash
   ps aux | cut -d' ' -f1,2,11
   ```

The `cut` command is particularly useful for processing structured text files, log files, and in shell scripts for data extraction and manipulation tasks.


### Input Sources

- Single file
- Multiple files
- Standard input (through pipes)

### Common Options

- `-i`: Ignore case
- `-v`: Invert match (print non-matching lines)
- `-n`: Print line numbers
- `-c`: Print only the count of matching lines
- `-l`: Print only the names of files with matches

## Extended Regular Expressions in egrep

### Additional Metacharacters

1. `+`: One or more occurrences
2. `?`: Zero or one occurrence
3. `|`: Alternation (OR)
4. `()`: Grouping
5. `{}`: Specify exact number of occurrences

### Character Classes

- `[[:alnum:]]`: Alphanumeric characters
- `[[:alpha:]]`: Alphabetic characters
- `[[:lower:]]`: Lowercase letters
- `[[:upper:]]`: Uppercase letters
- `[[:digit:]]`: Digits
- `[[:space:]]`: Whitespace characters
- `[[:punct:]]`: Punctuation characters

### Shorthand Notations

- `\w`: Word characters (equivalent to `[[:alnum:]_]`)
- `\W`: Non-word characters
- `\s`: Whitespace characters
- `\S`: Non-whitespace characters

## egrep Examples

1. Find lines ending with punctuation:
   ```bash
   egrep '[[:punct:]]$' file.txt
   ```

2. Find lines with only whitespace:
   ```bash
   egrep '^\s+$' file.txt
   ```

3. Find lines starting with uppercase letter, followed by period and whitespace:
   ```bash
   egrep '^[[:upper:]]\.\s' file.txt
   ```

4. Find lines starting with uppercase letter or whitespace:
   ```bash
   egrep '^([[:upper:]]|\s)' file.txt
   ```

## Best Practices

- Use single quotes around patterns to prevent shell interpretation
- Combine egrep with other commands using pipes for complex text processing
- Use appropriate character classes and shorthand notations for cleaner patterns
- Consider using egrep instead of grep when working with complex patterns that require extended regular expressions

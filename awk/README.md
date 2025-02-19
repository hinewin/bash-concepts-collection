# AWK Notes Summary

## Introduction to AWK

AWK is a powerful text processing utility named after its creators Aho, Kernighan, and Weinberger. It functions as a filter, accepting multiple lines of input, applying changes, and producing output. AWK offers more advanced features compared to sed, including programming constructs like expressions, operators, loops, conditionals, and functions.

## Key Concepts

### Records and Fields

- AWK views input as records and fields. Typically a record is 1 input line.
- Default record separator: newline character
  - Each record (line) is made up of multiple fields with a field separator (FS)
  - Default field separator: space or tab. Multiple spaces or tabs are considered a single delimiter.
- Each line and record goes into a buffer.
  - Ex:
  ```bash
  Line1: This is line 1
  # Record Buffer: This is line 1
  # Fields Buffer: Line1:, This, is, line, 1
  ```
- Fields are accessed using $1, $2, etc. $0 represents the entire record.
- CLI Format: `awk 'pattern { action }' file_list`
  - Multiple instructions can be separated by `;`
- Script Format: `awk -f script_name file_list`
  - Loops and branching can be used in the script.

### The -F option

- The `-F` option allows you to specify a different field separator.
- `awk -F 'c' 'pattern { action }' file_name`
  - `c` is the field separator.
  - Ex:
```awk
awk -F ',' '{ print $2 }' fileA
```
  - This will print the second field of every line of fileA

### Variables in AWK Script Format

- **Built-in Variables:**
  - **NR:** Number of Record
    - Awk processes each line of input as a record, and stores the current record number in NR
    - NR starts at 1 when the first input line is read
    - `NR == 8 ` will check if the line number is 8
  - **NF:** Number of Fields
    - Awk stores the number of fields in the current record in NF
    - `NF == 3` will check if the number of fields is 3
  - **FS:** Field Separator (input)
    - Equivalent to `-F` option in CLI format
  - **OFS:** Output Field Separator
    - Specifies how awk will separate fields in the output
    - Default is a space
    - `OFS = "\t"` will separate fields with a tab

- **User-defined Variables:**
  - Variables can be created while the input lines are being processed
  - Created using: `varName = data`, dynamically typed (no need for data type declaration)
  - No need for `$` in front of the variable name unlike a Shell variable
  - Ex:


### Patterns and Actions

- AWK instructions follow the format: `pattern { action }`
  - `pattern` is optional and used to select input lines
  - If no pattern is specified, the action will be applied to all input lines
  - There are 3 types of patterns:
    - **Simple Patterns:** `BEGIN`, `END`
      - `BEGIN` is executed before the first input line is read
      - `END` is executed after the last input line is read
      ```bash
      BEGIN { print "Start processing..."
                             FS = ":"} fileA
      # Print the starting text and set `FS`, then read in the first input line

      END { print "The sum is", total } fileA
      # After the last input line is read, print the text and the total before exiting
      ```
    - **Range Patterns:** `start_pattern, end_pattern`
      - The pattern matches lines between `start_pattern` and `end_pattern`
    - **Expression Patterns:** Regular expressions, Arithmetic, Relational, Logical
      - Awk uses regular expressions to match patterns
        - `/regex/` with `~` match and `!~` no match
        - To test whether the entire line matches the regex:
        `/regex/` or `$0 ~ /regex/`
        - To test whether the field does not match the regex:
        `$2 !~ /regex/`
      - Arithmetic:
        ```
        + # add                   $2 + $3
        - # subtract              $2 - $3
        * # multiply              $2 * $3
        / # divide                $2 / $3
        % # modulus               $2 % $3
        ^ # power                 $2 ^ $3
        -- # unary minus          $2-- ($2 = $2 - 1)
        ++ # unary plus           $2++ ($2 = $2 + 1)
        = # assignment            $2 = 5 ($2 = 5)
        += # add and assign       $2 += 5 ($2 = $2 + 5)
        -= # subtract and assign  $2 -= 5 ($2 = $2 - 5)
        *= # multiply and assign  $2 *= 5 ($2 = $2 * 5)
        /= # divide and assign    $2 /= 5 ($2 = $2 / 5)
        %= # modulus and assign   $2 %= 5 ($2 = $2 % 5)
        ```
      - Relational:
      ```bash
        == equal to
        != not equal to
        >  greater than
        >= greater than or equal to
        <  less than
        <= less than or equal to
      ```
      - Logical:
      ```bash
        && logical AND
        || logical OR
        ! logical NOT
      ```
  - Examples:
```awk
awk '$2 ~ /^\$/ $$ $3 >$4' fileA  # Field 2 starts with `$` symbol and field 3 is greater than field 4
awk 'NR == 2 || NR == 14' fileA   # Line number is 2 or 14
awk '$5 % 10' fileA               # Field 5 is not a multiple of 10
awk '$4 + $2 == $1' fileA         # The sum of fields 4 and 2 equals field 1
awk '$3 !~ /s$/' fileA            # Field 3 does not end with `s`
```

### Actions

- Print: `print`, `printf`, `sprintf`
  - `print` is used to print the values of fields
  - `printf` is used to format the output
    - Common field specifications: %d (integer), %f (float), %s (string)
    - Example:
    ```bash
    {printf ("Item: %s\t$%.2f\n", $1, $2)}
    # Item: Item1    $100.00
    ```
  - `sprintf` (Optional for advanced C programmers)
    - Create and format a string from variables
- Calculations using arithmetic operators
- String functions: `length()`, `split()`, `toupper()`, `tolower()`
  - Example of toupper
  ```bash
  {printf ("%-20s\t%8.2f\n", toupper($2), $3 + $4)
     total += $3 + $4 }
  ```

## Programming Constructs

### Control Structures

- **if statements**:
  - Used to execute code conditionally.
  - Syntax:
    ```awk
    if (condition) {
        # actions
    } else if (another_condition) {
        # other actions
    } else {
        # default actions
    }
    ```
  - Example:
    ```awk
    if ($1 > 100) {
        print "High value:", $1
    } else {
        print "Value:", $1
    }
    ```

- **Loops**:
  - **while**: Repeats actions as long as a condition is true.
    ```awk
    while (condition) {
        # actions
    }
    ```
  - **do-while**: Similar to while, but the condition is checked after the loop body is executed.
    ```awk
    do {
        # actions
    } while (condition)
    ```
  - **for**: Iterates over a range of values.
    ```awk
    for (i = 1; i <= NF; i++) {
        print $i
    }
    ```
  - **for-in**: Iterates over elements in an associative array.
    ```awk
    for (key in array) {
        print key, array[key]
    }
    ```

- **Arrays (Associative Arrays)**:
  - AWK supports associative arrays, which use strings as indices.
  - Useful for counting occurrences or storing key-value pairs.
  - Example:
    ```awk
    count[$1]++
    for (word in count) {
        print word, count[word]
    }
    ```
  - Associative arrays are dynamic and do not require explicit declaration.
  - An associative array can be created with the strings "0", "1", "2", "3", etc. as keys. This allows the array to behave like a regular 1D array.
  - Example: The `split` function divides a string into substrings and stores each substring as an element of an array using "1", "2", "3", etc. for the keys.
    ```awk
    myClass = "CIS 18B Adv Linux"
    split(myClass, arr, " ")
    { print arr[2] }  # This will print "18B"
    ```
  - Because the keys can be interpreted as numeric values, accessing `arr` is similar to accessing a regular 1D array.

## Special Use of Associative Arrays

- Associative arrays are very useful when we need to keep track of how many times an input event occurs, or keep track of the frequency of an input event.
- Example: Suppose `vehicleData.txt` contains lines of data representing different events recorded by an autonomous vehicle:
  ```
  stop_sign_detected
  pedestrian_crossing
  stop_sign_detected
  traffic_light_red
  pedestrian_crossing
  stop_sign_detected
  ```
  
  The following AWK script will print how many times each event appears in the file:
  ```awk
  {arr[$0]++}
  END {for(event in arr) print event, arr[event]}
  ```

- In the previous AWK script:
  - `{arr[$0]++}` increments the count for each event.
  - `END {for(event in arr) print event, arr[event]}` prints each event and its count.

- All the frequency counting is done in one line of code: `arr[$0]++`
  - As each event (line) is read in:
    - If there is no key that matches the event (first occurrence):
      - The event is stored as the key.
      - The associated data value is incremented from 0 (default initialized value) to 1.
    - If there is a key that matches the event (subsequent occurrence):
      - The associated data of the existing key is found and incremented.

- Example:
  1. `stop_sign_detected` is read in for the 1st time:
     - There is no key that matches `stop_sign_detected`:
       - Create key `stop_sign_detected`
       - Increment associated data from 0 to 1: `arr[stop_sign_detected] = 1`
  2. `stop_sign_detected` is read in for the 2nd time:
     - Key `stop_sign_detected` already exists:
       - Find associated data and increment it: `arr[stop_sign_detected] = 2`

- By the time all the input lines have been read in and the instruction `{arr[$0]++}` has been applied to each line, the associative array has keys that are unique events, and their associated data is the number of occurrences of each event.
- Then the `END` block uses a `for in` loop to print the event and their number of occurrences:
  ```awk
  END {for(event in arr) print event, arr[event]}
  ```

## Best Practices

- Use descriptive variable names
- Comment your AWK scripts for clarity
- Utilize AWK's built-in functions and operators for efficient text processing


# Module 3 Exercise - Solution

--------------------------------------------
Referencing file: `sed_input1.txt`

--------------------------------------------
1. Run the p command of sed with the file sed_input1 but don't print duplicate lines.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed -n 'p' sed_input1
   ```

   Explanation:
   - `sed`: Stream editor for filtering and transforming text.
   - `-n`: Suppresses automatic printing of pattern space.
   - `'p'`: Prints the current pattern space.

   </details>

--------------------------------------------
2. Print a line number and then print each line of sed_input1.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed '=' sed_input1
   ```

   Explanation:
   - `'='`: Prints the line number followed by a newline.

   </details>

--------------------------------------------
3. Add a *new line* that contains the word NEW, before all lines that have the word 'line'.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed '/line/ i NEW' sed_input1
   ```

   Explanation:
   - `'/line/'`: Matches lines containing the word 'line'.
   - `'i NEW'`: Inserts the line 'NEW' before each matching line.

   </details>

--------------------------------------------
4. Add the word NEW in front of all lines that have the word 'line' (The word NEW should be on the same line).

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed '/line/ s/^/NEW /' sed_input1
   ```

   Explanation:
   - `'/line/'`: Matches lines containing the word 'line'.
   - `'s/^/NEW /'`: Substitutes the start of the line with 'NEW '.

   </details>

--------------------------------------------
5. Change the last line so it says: This is 10.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed '$c  This is 10' sed_input1
   ```

   Explanation:
   - `'$'`: Refers to the last line.
   - `'c  This is 10'`: Changes the line to 'This is 10'.

   </details>

--------------------------------------------
6. Delete all lines that have a number in it.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed '/[0-9]/d' sed_input1
   ```

   Explanation:
   - `'[0-9]'`: Matches any digit.
   - `'d'`: Deletes the matching lines.

   </details>

--------------------------------------------
7. Delete all lines that don't have a number in it.

   <details>
   <summary><strong>Longer answer:</strong></summary>
   
   ```bash
   sed -r '/^[^0-9]+$/d' sed_input1
   # Use anchor `^` and `$` and `[^0-9]+` to match lines that don't contain a digit.
   # The `+` is crucial, it means one or more of the preceding character.
   ```

   Explanation:
   - `-r`: Enables extended regular expressions.
   - `'^/[^0-9]+/d'`: Deletes lines that do not contain a digit.

   </details>

   <details>
   <summary><strong>Shorter answer:</strong></summary>
   
   ```bash
   sed '/[0-9]/! d' sed_input1
   ```

   Explanation:
   - `'! d'`: Deletes lines that do not match the pattern.

   </details>

--------------------------------------------
8. Change all words 'line' to 'LINE' and print all lines.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed 's/line/LINE/' sed_input1
   ```

   Explanation:
   - `'s/line/LINE/'`: Substitutes 'line' with 'LINE'.

   </details>

--------------------------------------------
9. Change all words 'line' to 'LINE' but print only the lines that are changed.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   sed -n 's/line/LINE/p' sed_input1
   ```

   Explanation:
   - `-n`: Suppresses automatic printing.
   - `'p'`: Prints only the lines where substitutions occurred.

   </details>

--------------------------------------------
10. Print all lines up to the first line with the word 'Line'.

    <details>
    <summary><strong>Answer:</strong></summary>
    
    ```bash
    sed -n '1,/Line/p' sed_input1
    ```

    Explanation:
    - `'1,/Line/'`: Matches from the first line to the first occurrence of 'Line'.
    - `'p'`: Prints the matching lines.

    </details>

    <details>
    <summary><strong>Or faster, especially when the input file is large:</strong></summary>
    
    ```bash
    sed '/Line/q' sed_input1
    ```

    Explanation:
    - `'/Line/q'`: Quits after the first line containing 'Line', printing all lines up to that point.

    </details>

--------------------------------------------
### Referencing file: `sed_input2.txt`

--------------------------------------------
11. Print all lines but add a line of +++++ before and after each line.

    <details>
    <summary><strong>Answer:</strong></summary>
    
    Create a sed script named e11.sed with the following lines:
    ```bash
    # script for exercise 11 of module 3
    i +++++
    a +++++
    ```
    To run the script:
    ```bash
    sed -f e11.sed sed_input2.txt
    ```

    Explanation:
    - `'i +++++'`: Inserts '+++++' before each line.
    - `'a +++++'`: Appends '+++++' after each line.
    - `-f e11.sed`: Uses the specified script file.

    </details>

--------------------------------------------
12. Print all afternoon classes: in column format (with tab delimiter), with one line per class.

    <details>
    <summary><strong>Answer:</strong></summary>
    
    ```bash
    sed -n '/afternoon/,$ s/;/\t/gp' sed_input2.txt
    ```

    Explanation:
    - `'/afternoon/,$'`: Matches from the first occurrence of 'afternoon' to the end of the file.
    - `'s/;/\t/g'`: Replaces semicolons with tabs.
    - `'p'`: Prints the matching lines.

    </details>

    <details>
    <summary><strong>Or:</strong></summary>
    
    ```bash
    sed -n '/afternoon/,$ { y/;/\t/ ; /[0-9]/ p }' sed_input2.txt
    ```

    Explanation:
    - `'y/;/\t/'`: Translates semicolons to tabs.
    - `'/[0-9]/ p'`: Prints lines containing numbers.

    </details>

--------------------------------------------
13. Print the day and time of CIS classes, with a heading of "CIS classes day and time" and with data in column format.

    <details>
    <summary><strong>Answer:</strong></summary>
    
    Create a sed script named e13.sed with the following lines:
    ```bash
    # sed script for exercise 13 of module 3
    1i CIS classes day and time
    /cis/ { y/;/\t/
            p  }
    ```
    Run:
    ```bash
    sed -nf e13.sed sed_input2.txt
    ```

    Explanation:
    - `'1i CIS classes day and time'`: Inserts the heading at the beginning.
    - `'/cis/'`: Matches lines containing 'cis'.
    - `'y/;/\t/'`: Translates semicolons to tabs.
    - `'p'`: Prints the matching lines.
    - `-nf e13.sed`: Uses the specified script file without automatic printing.

    </details>

--------------------------------------------

Extra exercise with substitute and back reference

<details>
<summary><strong>Print all lines with == in front and == at the end.</strong></summary>

**Answer:**
```bash
sed 's/.*/==&==/' sed_input2.txt
```

Explanation:
- `'s/.*/==&==/'`: Substitutes the entire line with '==' at the beginning and end, where `&` represents the whole matched line.

</details>

<details>
<summary><strong>Print only the first field of CIS classes.</strong></summary>

**Answer:**
```bash
sed -nr '/cis/ s/(.*);.*;.*;.*;.*/\1/p' sed_input2.txt
```

Explanation:
- `-nr`: Suppresses automatic printing and enables extended regular expressions.
- `'/cis/'`: Matches lines containing 'cis'.
- `'s/(.*);.*;.*;.*;.*/\1/'`: Captures the first field before the first semicolon and prints it.

</details>
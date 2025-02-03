# Module 3 Exercise - Solution

--------------------------------------------
Copy the file module3Ainput from the cis18b directory to your current directory. Use this file as input for the next 10 questions.

--------------------------------------------
1. Run the p command of sed with the file module3Ainput but don't print duplicate lines.

   **Answer:**
   ```bash:bash-concepts-collection/sed/module3exerciseSolution
   sed -n 'p' module3Ainput
   ```

--------------------------------------------
2. Print a line number and then print each line of module3Ainput.

   **Answer:**
   ```bash
   sed '=' module3Ainput
   ```

--------------------------------------------
3. Add a *new line* that contains the word NEW, before all lines that have the word 'line'.

   **Answer:**
   ```bash
   sed '/line/ i NEW' module3Ainput
   ```

--------------------------------------------
4. Add the word NEW in front of all lines that have the word 'line' (The word NEW should be on the same line).

   **Answer:**
   ```bash
   sed '/line/ s/^/NEW /' module3Ainput
   ```

--------------------------------------------
5. Change the last line so it says: This is 10.

   **Answer:**
   ```bash
   sed '$c  This is 10' module3Ainput
   ```

--------------------------------------------
6. Delete all lines that have a number in it.

   **Answer:**
   ```bash
   sed '/[0-9]/d' module3Ainput
   ```

--------------------------------------------
7. Delete all lines that don't have a number in it.

   **Longer answer:**
   ```bash
   sed -r '^/[^0-9]+/d' module3Ainput
   ```

   **Shorter answer:**
   ```bash
   sed '/[0-9]/! d' module3Ainput
   ```

--------------------------------------------
8. Change all words 'line' to 'LINE' and print all lines.

   **Answer:**
   ```bash
   sed 's/line/LINE/' module3Ainput
   ```

--------------------------------------------
9. Change all words 'line' to 'LINE' but print only the lines that are changed.

   **Answer:**
   ```bash
   sed -n 's/line/LINE/p' module3Ainput
   ```

--------------------------------------------
10. Print all lines up to the first line with the word 'Line'.

    **Answer:**
    ```bash
    sed -n '1,/Line/p' module3Ainput
    ```

    **Or faster, especially when the input file is large:**
    ```bash
    sed '/Line/q' module3Ainput
    ```

--------------------------------------------
Copy the file module3Binput to your current directory. The module3Binput will be the input file for the next 3 questions below, which uses a sed script.

--------------------------------------------
11. Print all lines but add a line of +++++ before and after each line.

    **Answer:**
    Create a sed script named e11.sed with the following lines:
    ```bash
    # script for exercise 11 of module 3
    i +++++
    a +++++
    ```
    To run the script:
    ```bash
    sed -f e11.sed module3Binput
    ```

--------------------------------------------
12. Print all afternoon classes: in column format (with tab delimiter), with one line per class.

    **Answer:**
    ```bash
    sed -n '/afternoon/,$ s/;/\t/gp' module3Binput
    ```

    **Or:**
    ```bash
    sed -n '/afternoon/,$ { y/;/\t/ ; /[0-9]/ p }' module3Binput
    ```

--------------------------------------------
13. Print the day and time of CIS classes, with a heading of "CIS classes day and time" and with data in column format.

    **Answer:**
    Create a sed script named e13.sed with the following lines:
    ```bash
    # sed script for exercise 13 of module 3
    1i CIS classes day and time
    /cis/ { y/;/\t/
            p  }
    ```
    Run:
    ```bash
    sed -nf e13.sed module3Binput
    ```

=================================================
Extra exercise with substitute and back reference

Print all lines with == in front and == at the end.

**Answer:**
```bash
sed 's/.*/==&==/' module3Binput
```

--------------------------------------------
Print only the first field of CIS classes.

**Answer:**
```bash
sed -nr '/cis/ s/(.*);.*;.*;.*;.*/\1/p' module3Binput
```
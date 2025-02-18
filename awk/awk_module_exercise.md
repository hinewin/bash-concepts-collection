# awk Module Exercise - Solutions

--------------------------------------------
Referencing file: `awk_input.txt`

--------------------------------------------
1. Show the output of the `who` command, with each line starting with a line number, followed by a tab, then the output line.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   who | awk '{print NR "\t" $0}'
   ```

   Explanation:
   - `who`: Command to list users currently logged in.
   - `awk '{print NR "\t" $0}'`: Prints the line number followed by a tab and the entire line.

   </details>

--------------------------------------------
2. Show the user id (first field) of the `who` command, for lines 3 to 8 only.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   who | awk 'NR>=3 && NR<=8 {print $1}'
   ```

   Explanation:
   - `NR>=3 && NR<=8`: Processes lines 3 to 8.
   - `print $1`: Prints the first field (user id).

   </details>

--------------------------------------------
3. For all users currently logged in, show only the user ids and time logged in, then end with the text "Total:" followed by the total count of users logged in.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   who | awk '{print $1, $4} END {print "Total:", NR}'
   ```

   Explanation:
   - `print $1, $4`: Prints user id and time logged in.
   - `END {print "Total:", NR}`: Prints the total number of users.

   </details>

--------------------------------------------
4. For all users currently logged in, show user ids that have digits or punctuation marks in them.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   who | awk '$1 ~ /[[:digit:][:punct:]]/ {print $1}'

   # OR
   who | awk '$1 ~ /[0-9[:punct:]]/ {print $1}'
   ```

   Explanation:
   - `$1 ~ /[[:digit:][:punct:]]/`: Matches user ids with digits or punctuation.
   - `print $1`: Prints the matching user ids.


   </details>

--------------------------------------------
### Reference: `awk_input.txt`
- This file has information about the community colleges in
California. 
- The fields are separated by `;`  and they
are: 
  - school district
  - school name
  - enrollment in credit classes
  - enrollment in non-credit classes
  (The enrollment number
  is a full-time equivalent number, so it's not quite a head
  count and therefore is not a whole number).
--------------------------------------------
5. Print the name of the schools that have more than 10000 full-time equivalent students.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   awk -F';' '$3 + $4 > 10000 {print $2}' awk_input.txt
   ```

   Explanation:
   - `-F';'`: Sets the field separator to semicolon.
   - `$3 + $4 > 10000`: Checks if the sum of credit and non-credit enrollments is greater than 10000.
   - `print $2`: Prints the school name.

   </details>

--------------------------------------------
6. Print the average number of students across all colleges.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   awk -F';' 'BEGIN {total = 0} {total += $3 + $4} END {print "Average:", total/NR}' awk_input.txt
   ```

   Explanation:
   - `BEGIN {total = 0}`: Initializes the total to 0.
   - `{total += $3 + $4}`: For each line, add enrollments and set to `total`
   - `END {print "Average:", total/NR}`: Calculate and print the average after all lines are processed
   <details>
   <summary><strong>Script Format Answer</strong></summary>

      ```bash
      # Set field separator to ; and initialize total to 0
      BEGIN {FS=";"
             total = 0}

      # For every line, add field 3 & 4 and set to total
      {total += $3 + $4}

      # At the end, print the average
      END {print "Average:", total/NR}
   ```
      </details>

--------------------------------------------
7. Print a header line of "School    Enrollment", then list all school names in uppercase and number of students of each school, end by printing the total number of students of all schools.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   BEGIN {FS = ";"
            total = 0
            print "School\t\tEnrollment"}
   { printf ("%-20s\t%8.2f\n", toupper($2), $3 + $4)
     total += $3 + $4 }
   END {printf ("Total: %.2f\n", total)}' awk_input.txt
   ```

   </details>

--------------------------------------------
8. Print the school name and enrollment number of the school with the largest enrollment number.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   BEGIN {FS = ";"
          largest = 0 }
   $3 + $4 > largest { largest = $3 + $4 
                       name = $2 }
   END { print name, largest}
   ```

   Explanation:
   - Initializes largest as 0
   - For every line where $3 + $4 is greater than largest, that will be the new largest
     - set the new largest value and school name

   </details>

--------------------------------------------
9. For the file `clean.sh`:
   - Print the total number of comment lines and total number of words in the comment lines.
   - Print text explanation for each value you print.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   BEGIN {totalLines = 0
          totalWords = 0}
   /^# / {totalLines++
          totalWords += NF}
   END {print "Total comment lines:", totalLines
        print "Total words in comment lines:", totalWords}
   ```

   Explanation:
   - Initializes totalLines and totalWords to 0
   - For every line that starts with `# `, increment totalLines and add the number of fields to totalWords
   - At the end, print the total number of comment lines and the total number of words in the comment lines

   </details>

--------------------------------------------
10. Print the lines of code of `clean.sh` in reverse (last line first, first line last). Lines of code means no comment lines and no blank lines.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   BEGIN arr[i] = 0

   NR == 1 || /^[^#]/ && /./ {arr[i++]= $0}

   END = {for (j = i -1; j >0; i--)
          print arr[j]}
```
   Explanation:
   - `BEGIN arr[i] = 0`: Initializes the array to 0
   - `NR == 1 || /^[^#]/ && /./ {arr[i++]= $0}`: Stores lines in an array if its the first line or not a comment line and has content
   - `for (j = i -1; j >0; i--)`
     -  Starting from the last index of the array, as j is less than 0, decrement j and print the line

   </details>

--------------------------------------------
11. Print the characters that are present in line 3 of `clean.sh`, and, next to each character, print a count of how many of these characters are in the lines.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   awk 'NR == 3 {for (i = 1; i <= length($0); i++) chars[substr($0, i, 1)]++} NR > 3 {for (i = 1; i <= length($0); i++) if (chars[substr($0, i, 1)]) count[substr($0, i, 1)]++} END {for (c in chars) print c, count[c]}' clean.sh
   ```

   Explanation:
   - `NR == 3`: Processes the third line to count characters.
   - `chars[substr($0, i, 1)]++`: Counts characters in line 3.
   - `NR > 3`: Processes subsequent lines.
   - `count[substr($0, i, 1)]++`: Counts occurrences of characters from line 3.
   - `END {for (c in chars) print c, count[c]}`: Prints characters and their counts.

   </details>

--------------------------------------------
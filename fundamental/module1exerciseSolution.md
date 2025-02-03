# Module 1 Exercise - Solution

Each question should be answered with one command line.

--------------------------------------
1. Copy files from the directory /home/distribution/cnguyen/cis18b. Set up a way to copy files easily from this directory.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   ln -s /home/distribution/cnguyen/cis18b 18b
   ```

   Explanation: Creates a symbolic link named `18b` to the directory for easy access.

   </details>

--------------------------------------
2. Using your setup from the step above, copy the file module1input from the 18b directory to your current directory.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   cp 18b/module1input .
   ```

   Explanation: Copies the file `module1input` from the `18b` directory to the current directory.

   </details>

--------------------------------------
3. Use a text editor to add one more class to module1input: pe 71 with 1 unit.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   vim module1input
   ```

   Explanation: Opens the file in `vim` editor.
   - `6G`          go to line 6
   - `o`           open a new line, go to insert mode
   - `pe,71,1`     type in line
   - `escape`      go back to command mode
   - `:wq`         save and quit

   </details>

--------------------------------------
4. Without using a text editor, create a new file called "m1" which has all the lines of module1input, except that all letters are in uppercase and each comma is changed to a space character.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   tr 'a-z,' 'A-Z ' < module1input > m1
   ```

   Explanation: Translates lowercase letters to uppercase and commas to spaces, outputting to `m1`.

   </details>

--------------------------------------
5. Show the file "m1" on screen.

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   cat m1
   ```

   Explanation: Displays the contents of the file `m1`.

   </details>

--------------------------------------
6. Show the long listing of "m1". What are the columns of attributes of file "m1" that the listing shows?

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   ls -l m1
   ```

   Explanation: Provides a detailed listing of `m1` with attributes like permissions, owner, size, etc.
   The columns are:
   - file type and permission
   - number of hard links
   - user id of owner
   - group of owner
   - number of bytes of data in the file
   - last access date and time
   - filename

   </details>

--------------------------------------
7. Without using a text editor, append to "m1" 2 lines: line 1: "classes" (with quotes), line 2: your terminal id.

   <details>
   <summary><strong>Answer with 2 command lines:</strong></summary>
   
   ```bash
   echo \"classes\" >> m1
   tty >> m1
   ```

   Explanation: Appends the line `"classes"` and the terminal ID to `m1`.

   </details>

   <details>
   <summary><strong>Answer with 1 command line:</strong></summary>
   
   ```bash
   (echo \"classes\" ; tty) >> m1
   ```

   Explanation: Combines both commands to append in one line.

   </details>

--------------------------------------
8. Create a new module1input file that is made of lines 2-7 of file "m1".

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   head -7 m1 | tail -6 > module1input
   ```

   Explanation: Extracts lines 2-7 from `m1` and writes them to `module1input`.

   </details>

--------------------------------------
9. Show number of lines in the file "m1".

   <details>
   <summary><strong>Answer:</strong></summary>
   
   ```bash
   wc -l m1
   ```

   Explanation: Counts and displays the number of lines in `m1`.

   </details>

--------------------------------------
10. Show on screen the lines that are 5 units, with the class names sorted in reverse alphabetical order.

    <details>
    <summary><strong>Answer:</strong></summary>
    
    ```bash
    egrep ' 5' m1 | sort -r
    ```

    Explanation: Filters lines containing '5' and sorts them in reverse order.

    </details>
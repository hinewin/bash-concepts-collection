# Module 5 (make)

## Initial Setup
Copy the directory `assignment1_files` from the `lab` directory. This is the directory where you will do your work.

## Source Files Overview
In this directory are some source files that work together to allow the user to multiply 2 numbers. The source files are:

- `main.cpp`: call functions in the other source files: `input.cpp`, `concat.cpp`, and `output.cpp`
- `input.cpp`: get the first name and last name from the user
- `concat.cpp`: concatenate the 2 names into one string
- `output.cpp`: print the string with some greeting messages

**Note**: Except for `main.cpp`, each source file has its own header file.

## Tasks

### 1. Create a Makefile
Write a makefile with the following specifications:
- When you type `make`, it will:
  - Build an executable called `greet` from the C++ source files
  - Print the text "filename is built" at the end (where filename is the name of the executable)
- Allow compiling each source file individually by typing: `make filename.o`
- Include 3 macros:
  1. Compiler name (set to g++)
  2. File dependencies
  3. Name of the executable (set to greet)

### 2. Build Input Object File
```bash
make input.o
```
Then do a listing of the directory to show that only this file was created.

### 3. Build Executable
```bash
make
```

### 4. Modify Source Code
Use one command line to change the following line in `concat.cpp`:
```cpp
return "Hi, " + s1 + " " + s2 + "\nWelcome to Lab 5";
```
to:
```cpp
return "Hi, " + s1 + " " + s2 + "\nWelcome to Lab 5!";
```
(Without using vim or any text editor, and without using line numbers)

### 5. Rebuild with Different Name
Build the executable again, but name it `hi.exe`

### 6. Explain Build Time Difference
Use echo to print an explanation for why the build in step 5 is shorter than the build in step 3.

### 7. Add Make Targets
Modify the makefile to add:
- `make clean`: delete all object files and executable file quietly
- `make list`: long listing of all .cpp files (command should not show on screen)

### 8. Testing
1. Show your output file on screen
2. Create 2 empty files called `clean` and `list`
3. Run the following commands in sequence:
   ```bash
   make list     # only .cpp files should be listed
   make clean    # all object and executable files removed
   make clean    # no error message
   make         # new executable built
   make         # should say executable is up to date
   ```

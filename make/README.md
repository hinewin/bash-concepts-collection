<img src="https://r2cdn.perplexity.ai/pplx-full-logo-primary-dark%402x.png" class="logo" width="120"/>

# 

---

# Convert this powerpoint into text format

## Introduction to make

make is a utility that helps manage file dependencies and automate the build process for software projects. It was originally created to assist software developers in building executable files, but has since found wider applications in system administration and other tasks involving file management.

## Key Concepts

**Source Files and Object Files**

- Source files (e.g., .cpp files in C++) contain the program code
- Object files (.o files) are created by compiling source files
- Executable files are created by linking object files

**File Dependencies**

- Object files depend on source files
- Executable files depend on object files
- When a source file changes, its corresponding object file needs to be recompiled
- When an object file changes, the executable needs to be relinked


## How make Works

make uses a script called a makefile to manage file dependencies and build processes. The makefile contains rules that specify:

1. Target files to be created
1. Dependencies for each target
1. Commands to create the target

make follows these steps:

1. Looks for a file named makefile or Makefile in the current directory
1. Runs the rules in a makefile recurseively to take care of layers of dependencies
   - If no rule is provided, it will use the first rule in the makefile
   - Put the final product of the build process in the first rule
1. If we want `make` to only produce a certain target file, then we type the target filename as an argument to `make`
```bash
make targetfilename
# Only rule(s) to produce targetfilename will be executed
```
1. Checks file timestamps to determine which files need updating
   - If a target file is newer than its dependencies, it is up to date
   - If a target file is older than any of its dependencies, the target is rebuilt
1. Runs only the necessary commands to update out-of-date files


## Makefile Structure

A makefile consists of rules in the following format:

```
target: dependencies
    command
```

- target: the file to be created or updated
- dependencies: files needed to produce the target
- command: the action to produce the target, which must be indented with a tab. A soft tab is not allowed.


## Macros in Makefiles

Macros are text substitutions that make it easier to manage repeated elements in a makefile:

```
# Define a macro
MACRO_NAME = space separated values

# Use a macro
$(MACRO_NAME)
```
We use them to represent the names of files, compiler flags, etc. In an example where we need to create an executable from multiple object files,
```makefile
myProgram: object1.o object2.o object3.o
    g++ -o myProgram object1.o object2.o object3.o
```
we can define a macro for the object files:
```makefile
OBJ = object1.o object2.o object3.o
# Now it's shorter to type the rule:
myProgram: $(OBJ)
    g++ -o myProgram $(OBJ)
```
### Common macros include:

  - `CFLAGS`-  represents compiler flags
    - `CFLAGS = -g -Wall` This will add debugging information and enable all warnings
    - Common flags for gcc or g++ compilers include:
      - `-g`: produce an executable with debugging information
      - `-Wall`: enable all warnings
      - `-O`: optimize the code
      - `O` option is not used with `-g` since code that has debugging information is not optimized

- `CC`: compiler name (`CC = gcc` or `CC = g++`)
- `$@`: name of the current target file
- `$^`: names of all dependency files

Example:
```makefile
name.o : name.cpp
    $(CC) $(CFLAGS) -c name.cpp
# This is the same as:
# g++ -g -Wall -c name.cpp -o name.o
```
### Changing Macro Value on the Command Line

Fortmat to specify a new macro value on the command line:
```bash
make MACRO_NAME=new_value

make CFLAGS='-O'
# Change the compiler flags to optimize the code
```


## Phony Targets

Phony targets are used to run commands that relate to the build process but do not produce a file output
- There is often no source file because `target` is just a label, not a file that needs to be produced
```makefile
cleanobject:
    rm *.o # Remove object files
cleanexe:
    rm *.exe # Remove executable files
cleanall: cleanobject cleanexe
# cleanall will run cleanobject first then cleanexe
```
- There is a potential danger with having a phony target like `clean` that doesnt produce a tartget file
- If another target file has the same name as the phony target, the phony target will be ignored because `make` thinks the target is up to date
- If we tell `make` that `clean` is a phony target, which is a target that is not a file, there will be no confusion.
```makefile
.PHONY: clean
clean:
    rm *.o
```
- When running command of a phony target, we don't need `make` to eacho the command to screen.
- Add `@` before the command to suppress the command echo.
```makefile
clean:
    @rm *.o
```

## Common Suffixes Rule

For repeated rules with common file extensions:

```makefile
%.o: %.cpp
    $(CC) $(CFLAGS) -c $^
```

This rule applies to all .cpp files to produce .o files.

## Conclusion

make is a powerful tool for managing complex projects with multiple files and dependencies. It automates the build process, ensuring that only necessary files are updated, saving time and reducing errors in software development and other file management tasks.
# Build Process in C++

## Visual Overview

```ascii
+------------------+                                +----------------+                              +-------------+
|  Source Code     |       g++ -c file.cpp         |  Object Code   |     g++ -o prog file.o      | Executable  |
| (helloWorld.cpp) | --------------------------->  | (helloWorld.o) | --------------------------> |   (prog)    |
+------------------+                                +----------------+                              +-------------+
     Contains:                                          Contains:                                     Contains:
   - Human readable                                   - Machine code                               - Runnable
   - C++ code                                        - Not executable                               program
   - Header includes                                 - Needs linking                              - Linked with
                                                                                                   libraries
```

## Build Commands

### Two-Step Build Process

1. **Compilation** (Source → Object)
   ```bash
   g++ -c helloWorld.cpp
   ```
   - `g++`: GNU C++ compiler
   - `-c`: Compile only (no linking)
   - Input: `.cpp` file
   - Output: `.o` file

2. **Linking** (Object → Executable)
   ```bash
   g++ -o hello helloWorld.o
   ```
   - `-o hello`: Name output as "hello"
   - Links object file with libraries
   - Creates final executable

### One-Step Build Process

```bash
g++ helloWorld.cpp
```
This single command:
- ✓ Compiles source to object code
- ✓ Links with standard libraries
- ✓ Creates executable (`a.out` by default)

## Key Points

### Object Files (.o)
- Contain compiled machine code
- Not yet executable
- Intermediate build step
- Can be linked with other object files

### Executables
- Final runnable program
- All dependencies resolved
- Linked with necessary libraries
- Ready to run on the system

### Standard Libraries
- Automatically linked
- Include common functions
- Example: `iostream` for I/O operations


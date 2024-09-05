# ReadProcessMemory Demo

This repository contains practice code for reading process memory in Windows using the `ReadProcessMemory` function. It includes two simple programs:

1. **Dummy Program**: A console application that declares a static integer variable (`varInt`) and prints its memory address and value.
2. **Memory Reader**: A program that uses `ReadProcessMemory` to read the value of `varInt` from the Dummy Program.

## How to Use

### Step 1: Compile and Run the Dummy Program
1. Build and run the `DummyProgram.cpp` file.
2. The program will print the memory addresses and values of `varInt`, `varString`, `arrChar`, and the pointers.
3. The program will keep running, allowing you to note the Process ID (PID) and memory addresses:
   - **Process ID**: This value will be used when running the `ReadProcessMemory` program.
   - Note down the memory address of `varInt`, as you will need this later.

### Step 2: Compile and Run the Memory Reader
1. Build and run the `ReadProcessMemory.cpp` file.
2. After running, enter the **PID** of the Dummy Program.
3. Then, input the memory address of `varInt` in hexadecimal (use the value printed by the Dummy Program).
4. The program will use `ReadProcessMemory` to read the value of `varInt` from the memory of the Dummy Program and print the result.

## Files

- `DummyProgram.cpp`: Source code for the Dummy Program.
- `ReadProcessMemory.cpp`: Source code for the Memory Reader.

## Disclaimer

This code is for educational purposes only. Reading or modifying the memory of other processes can be harmful or illegal if used improperly.

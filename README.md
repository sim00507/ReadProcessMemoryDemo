# ReadProcessMemory Demo

This repository contains practice code for reading process memory in Windows using the `ReadProcessMemory` function. It includes two simple programs:

1. **Dummy Program**: A console application that declares a static integer variable (`varInt`) and prints its memory address and value.
2. **Memory Reader**: A program that uses `ReadProcessMemory` to read the value of `varInt` from the Dummy Program.

## How to Use

### Step 1: Compile and Run the Dummy Program
- Build and run the `DummyProgram.cpp` file.
- Note the printed memory address of `varInt` and keep the program running.

### Step 2: Compile and Run the Memory Reader
- Build and run the `ReadProcessMemory.cpp` file.
- Input the process ID (PID) of the Dummy Program and the memory address of `varInt`.
- The program will read and print the value of `varInt` from the Dummy Program's memory.

## Files

- `DummyProgram.cpp`: Source code for the Dummy Program.
- `ReadProcessMemory.cpp`: Source code for the Memory Reader.

## Disclaimer

This code is for educational purposes only. Reading or modifying the memory of other processes can be harmful or illegal if used improperly.

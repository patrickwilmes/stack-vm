# Stack VM

Stack VM is a very simple vm using a stack for op code execution. The purpose of stack vm is purely educational.

## Compiling

```bash
mkdir build
cd build
cmake ..
make
```

## Running

```bash
./toyvm <TOY_FILE>
# Example
./toyvm resources/add.toy
```

## Op Codes
The vm is capable of performing simple arithmetics: add, subtract, multiply, divide two numbers and print them to stdout.

The op codes available at the moment are:
```asm
PSH 10 # push something on the stack
PSH 20
ADD # add the last two numbers that are on the top of the stack
PRT # print the current stack top to stdout
POP # pop the last entry from the stack
HLT # stop the program
```
Further operations are:
```asm
sub # subtract the last two numbers
div # divide the last two numbers
mul # multiplicate the last two numbers
```
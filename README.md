# Stack VM

Stack VM is a very simple vm using a stack for op code execution. The purpose of stack vm is purely educational. We are not working with binary code here, but with plan instructions (text) for the sake
of simplicity.
Maybe in the future we'll build an assembler.

## Compiling

```bash
# building with make
mkdir build
cd build
cmake ..
make

# Alternative with ninja
mkdir build
cd build
cmake .. -GNinja
ninja
```

## Running

```bash
./stack_vm <STACK_FILE>
# Example
./stack_vm resources/add.sv
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

## About stack based vms
Stack based vms are the most simple kind of virtual machines. They use a simple stack datastructures for execution.
Each op code will be parsed and loaded into memory. After loading the program into memory, the vm starts execution
of the first command. If we for example have two PSH (push) and one ADD operations the following will happen:

```
PHS 10 encountered so program instruction pointer increased by 1
and 10 pushed onto the value stack
PSH 20 encountered so program insturction pointer increased by 1
and 20 pushed onto the value stack
ADD encountered  so program instruction pointer increased by 1 and
vm will call 2 times pop on the stack which will return 20 and 10 (in the given order) and will add them.
```
Stack based virtual machines are nice from an educational point of view as they are very easy to implement and to
understand, but the practical used in limited.
Modern vms are register based vm. (Maybe I'll build one in the future.)
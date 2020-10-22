# Toy VM

Toy VM is a very simple stack based virtual machine implementing a custom basic instruction set.

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
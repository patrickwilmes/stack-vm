#include <iostream>
#include "preprocessing/Preprocessing.h"
#include "instructions.h"
#include "io/io.h"
#include "utils.h"

class Executor {
public:
    Executor(int (&program)[256]): program(program) {
        initializeIntArr(stack, 256);
    }

    Executor(int (*program)[256]): program(*program) {}
    ~Executor() = default;

    void execute() {
        bool running = true;
        int ip = 0;
        int sp = -1;
        while (running) {
            switch (program[ip]) {
                case HLT: {
                    running = false;
                    break;
                }
                case PSH: {
                    int val = program[ip+1];
                    stack[++sp] = val;
                    break;
                }
                case ADD: {
                    int a = stack[sp];
                    int b = stack[--sp];
                    int result = a + b;
                    stack[++sp] = result;
                    break;
                }
                case DIV: {
                    int a = stack[sp];
                    int b = stack[--sp];
                    int result = b / a;
                    stack[++sp] = result;
                    break;
                }
                case POP: {
                    int val = stack[sp--];
                    std::cout << val << std::endl;
                    break;
                }
            }
            ip++;
        }
    }

private:
    int stack[256];
    int (&program)[256];
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage ./toyvm <NAME>.toy" << std::endl;
        return -1;
    }

    int p[256];

    initializeIntArr(p, 256);

    loadProgram(argv[1], p);

    if (!isValidProgram(p)) {
        std::cerr << "Program doesn't contain HLT" << std::endl;
        return -1;
    }

    Executor executor(p);
    executor.execute();

    return 0;
}

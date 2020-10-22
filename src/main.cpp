#include <iostream>
#include "preprocessing/Preprocessing.h"

typedef enum {
    HLT,
    PSH,
    POP,
    ADD,
} Instructions;

class Executor {
public:
    Executor(int (&program)[256]): program(program) {
        for (int & i : stack) {
            i = -1;
        }
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
    int p[256];
    for (int & i : p) {
        i = -1;
    }
    p[0] = PSH;
    p[1] = 10;
    p[2] = PSH;
    p[3] = 20;
    p[4] = ADD;
    p[5] = POP;
    p[6] = HLT;

    if (!isValidProgram(p)) {
        std::cerr << "Program doesn't contain HLT" << std::endl;
        return -1;
    }

    Executor executor(p);
    executor.execute();

    return 0;
}

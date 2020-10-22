#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "preprocessing/Preprocessing.h"
#include "instructions.h"

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

int instructionFor(const std::string& cmd) {
    if (cmd == "PSH")
        return PSH;
    if (cmd == "ADD")
        return ADD;
    if (cmd == "POP")
        return POP;
    if (cmd == "HLT")
        return HLT;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage ./toyvm <NAME>.toy" << std::endl;
        return -1;
    }

    int p[256];
    for (int & i : p) {
        i = -1;
    }
    int pc = -1;
    std::cout << argv[1] << std::endl;
    std::ifstream infile(argv[1]);
    std::string line;
    std::string a;
    int b;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (!(iss >> a >> b)) {
            p[++pc] = instructionFor(a);
            continue;
        }
        p[++pc] = instructionFor(a);
        p[++pc] = b;
    }

    if (!isValidProgram(p)) {
        std::cerr << "Program doesn't contain HLT" << std::endl;
        return -1;
    }

    Executor executor(p);
    executor.execute();

    return 0;
}

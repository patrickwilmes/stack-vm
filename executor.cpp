#include <iostream>

#include "executor.h"
#include "instructions.h"

void StackExecutor::execute() {
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
            case SUB: {
                int a = stack[sp];
                int b = stack[--sp];
                int result = a - b;
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
            case MUL: {
                int a = stack[sp];
                int b = stack[--sp];
                int result = a * b;
                stack[++sp] = result;
                break;
            }
            case POP: {
                sp--;
                break;
            }
            case PRT: {
                int val = stack[sp];
                std::cout << val << std::endl;
                break;
            }
        }
        ip++;
    }

}

#include "parser.h"

#include <algorithm>
#include <sstream>

#include "instructions.h"

void parseProgramm(std::vector<std::string> &code, int *program) {
    int pc = -1;
    std::for_each(code.begin(), code.end(), [&pc, program](std::string &line){
        std::string cmd;
        int arg;
        std::istringstream iss(line);
        if (!(iss >> cmd >> arg)) {
            program[++pc] = instructionFor(cmd);
        } else {
            program[++pc] = instructionFor(cmd);
            program[++pc] = arg;
        }
    });
}

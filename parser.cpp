#include "parser.h"

#include <algorithm>
#include <sstream>

#include "instructions.h"

void parse_program(std::vector<std::string> &code, int *program) {
    int pc = -1;
    std::for_each(code.begin(), code.end(), [&pc, program](std::string &line){
        std::string cmd;
        int arg;
        std::istringstream iss(line);
        if (!(iss >> cmd >> arg)) {
            program[++pc] = get_instruction_for(cmd);
        } else {
            program[++pc] = get_instruction_for(cmd);
            program[++pc] = arg;
        }
    });
}

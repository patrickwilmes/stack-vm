#include "io.h"
#include <fstream>
#include <sstream>
#include <string>

#include "../instructions.h"

void loadProgram(const std::string& file, int *program) {
    int pc = -1;
    std::ifstream infile(file);
    std::string line;
    std::string a;
    int b;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        if (!(iss >> a >> b)) {
            program[++pc] = instructionFor(a);
            continue;
        }
        program[++pc] = instructionFor(a);
        program[++pc] = b;
    }
}


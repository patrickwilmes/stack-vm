#include "io.h"
#include <fstream>
#include <sstream>
#include <string>

#include "../instructions.h"

void loadProgram(const std::string& file, std::vector<std::string> &code) {
    std::ifstream infile(file);
    std::string line;
    std::string a;
    while (std::getline(infile, line)) {
        code.push_back(line);
    }
}

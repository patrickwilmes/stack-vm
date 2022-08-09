#include "io.h"
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <iostream>


int load_program(const std::string& file, std::vector<std::string> &code) {
    if (!std::filesystem::exists(file)) {
        std::cerr << "file " << file << " does not exist!" << std::flush;
        return -1;
    }
    std::ifstream infile(file);
    std::string line;
    std::string a;
    while (std::getline(infile, line)) {
        code.push_back(line);
    }
    return 1;
}

#include "Preprocessing.h"
#include <algorithm>
#include "../utils.h"

std::vector<std::string> removeComments(std::vector<std::string> &code) {
    std::vector<std::string> cleanCode;
    std::for_each(code.begin(), code.end(), [&cleanCode](std::string& line){
        ltrim(line);
        if (line.length() > 0) {
            if (line.at(0) != ';') {
                cleanCode.push_back(line);
            }
        }
    });
    return cleanCode;
}


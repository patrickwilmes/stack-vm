#include "preprocessing.h"
#include <algorithm>
#include "utils.h"

std::vector<std::string> remove_comments(std::vector<std::string> &code) {
    std::vector<std::string> cleaned_code;
    std::for_each(code.begin(), code.end(), [&cleaned_code](std::string& line){
        ltrim(line);
        if (line.length() > 0) {
            if (line.at(0) != ';') {
                cleaned_code.push_back(line);
            }
        }
    });
    return cleaned_code;
}


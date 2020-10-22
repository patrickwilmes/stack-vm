#ifndef TOYVM_UTILS_H
#define TOYVM_UTILS_H

#include <string>
#include <algorithm>

inline void initializeIntArr(int *arr, unsigned int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = -1;
    }
}

inline static void ltrim(std::string &line) {
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char c){
        return !std::isspace(c);
    }));
}

#endif //TOYVM_UTILS_H

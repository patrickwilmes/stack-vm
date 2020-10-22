#ifndef TOYVM_IO_H
#define TOYVM_IO_H

#include <string>
#include <vector>

void loadProgram(const std::string& file, int *program);
void loadProgram(const std::string& file, std::vector<std::string> &code);

#endif //TOYVM_IO_H

#ifndef TOYVM_PREPROCESSING_H
#define TOYVM_PREPROCESSING_H

#include <string>
#include <vector>

std::vector<std::string> removeComments(std::vector<std::string> &code);

bool isValidProgram(int (&program)[256]);

#endif //TOYVM_PREPROCESSING_H

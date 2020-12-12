#ifndef TOYVM_INSTRUCTIONS_H
#define TOYVM_INSTRUCTIONS_H

#include <map>
#include <string>

typedef enum {
    HLT,
    PSH,
    POP,
    ADD,
    SUB,
    DIV,
    MUL,
    PRT
} Instructions;

inline static std::map<std::string, Instructions> instructionMappings = {
        {"HLT", HLT},
        {"PSH", PSH},
        {"POP", POP},
        {"ADD", ADD},
        {"SUB", SUB},
        {"DIV", DIV},
        {"MUL", MUL},
        {"PRT", PRT},
};

inline int instructionFor(const std::string& cmd) {
    return instructionMappings[cmd];
}
#endif //TOYVM_INSTRUCTIONS_H

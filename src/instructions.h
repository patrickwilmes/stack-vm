#ifndef TOYVM_INSTRUCTIONS_H
#define TOYVM_INSTRUCTIONS_H

#include <map>
#include <string>

typedef enum {
    HLT,
    PSH,
    POP,
    ADD,
    DIV,
    MUL,
} Instructions;

inline static std::map<std::string, Instructions> instructionMappings = {
        {"HLT", HLT},
        {"PSH", PSH},
        {"POP", POP},
        {"ADD", ADD},
        {"DIV", DIV},
        {"MUL", MUL},
};

inline int instructionFor(const std::string& cmd) {
    return instructionMappings[cmd];
}
#endif //TOYVM_INSTRUCTIONS_H

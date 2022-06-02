#ifndef STACKVM_INSTRUCTIONS_H
#define STACKVM_INSTRUCTIONS_H

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

inline static std::map<std::string, Instructions> instruction_mappings = {
        {"HLT", HLT},
        {"PSH", PSH},
        {"POP", POP},
        {"ADD", ADD},
        {"SUB", SUB},
        {"DIV", DIV},
        {"MUL", MUL},
        {"PRT", PRT},
};

inline int get_instruction_for(const std::string& cmd) {
    return instruction_mappings[cmd];
}
#endif //STACKVM_INSTRUCTIONS_H

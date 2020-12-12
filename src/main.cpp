#include <iostream>
#include "preprocessing/Preprocessing.h"
#include "io/io.h"
#include "utils.h"
#include "parser.h"
#include "executor.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage ./stack_vm <NAME>.sv" << std::endl;
        return -1;
    }

    int p[256];

    initializeIntArr(p, 256);

    std::vector<std::string> code;
    loadProgram(argv[1], code);
    code = removeComments(code);

    parseProgramm(code, p);

    StackExecutor executor(p);
    executor.execute();

    return 0;
}

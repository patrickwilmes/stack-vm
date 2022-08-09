#include <iostream>
#include "preprocessing/preprocessing.h"
#include "io/io.h"
#include "utils.h"
#include "parser.h"
#include "executor.h"

int main(int argc, char* argv[]) {
    /*
    We expect a single argument which is the path to a *.sv (stack-vm) file
    containing the instructions to execute.
    */
    if (argc != 2) {
        std::cerr << "Usage ./stack_vm <NAME>.sv" << std::endl;
        return -1;
    }

    /*
    We store the instructions in the following int array.
    */
    int program[256];

    initialize_int_array(program, 256);

    std::vector<std::string> code;
    if (!load_program(argv[1], code)) {
        std::cerr << "Failed to load program!\n" << std::flush;
        return -1;
    }
    code = remove_comments(code);

    parse_program(code, program);

    StackExecutor executor(program);
    executor.execute();

    return 0;
}

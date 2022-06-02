#include <iostream>
#include "preprocessing/preprocessing.h"
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

    initialize_int_array(p, 256);

    std::vector<std::string> code;
    if (!load_program(argv[1], code))
        return -1;
    code = remove_comments(code);

    parse_program(code, p);

    StackExecutor executor(p);
    executor.execute();

    return 0;
}

#ifndef STACKVM_EXECUTOR_H
#define STACKVM_EXECUTOR_H

#include "utils.h"

class Executor {
public:
    explicit Executor(int (&program)[256]): program(program) {}

    ~Executor() = default;

    virtual void execute() = 0;

protected:
    int (&program)[256];
};

class StackExecutor: public Executor {
public:
    explicit StackExecutor(int (&program)[256]) : Executor(program) {
        initialize_int_array(stack, 256);
    }
    void execute() override;
private:
    int stack[256]{};
};

#endif //STACKVM_EXECUTOR_H

#ifndef TOYVM_EXECUTOR_H
#define TOYVM_EXECUTOR_H

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
    StackExecutor(int (&program)[256]) : Executor(program) {
        initializeIntArr(stack, 256);
    }
    void execute() override;
private:
    int stack[256]{};
};

#endif //TOYVM_EXECUTOR_H

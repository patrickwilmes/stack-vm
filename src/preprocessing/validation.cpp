#include "Preprocessing.h"
#include "../instructions.h"

bool isValidProgram(int (&program)[256]) {
    bool containsHlt = false;
    for (int i : program) {
        if (i == HLT) {
            containsHlt = true;
        }
    }
    return containsHlt;
}

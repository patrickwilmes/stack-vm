#include "Preprocessing.h"

bool isValidProgram(int (&program)[256]) {
    bool containsHlt = false;
    for (int i : program) {
        if (i == 0) {
            containsHlt = true;
        }
    }
    return containsHlt;
}

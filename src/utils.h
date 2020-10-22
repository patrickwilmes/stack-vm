#ifndef TOYVM_UTILS_H
#define TOYVM_UTILS_H

inline void initializeIntArr(int *arr, unsigned int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = -1;
    }
}

#endif //TOYVM_UTILS_H

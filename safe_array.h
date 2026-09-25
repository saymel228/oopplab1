#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

struct SafeArray {
    int* data;
    int size;
};

SafeArray createArray(int size);
int& getElement(SafeArray& arr, int index);
void printSafe(const SafeArray& arr);
SafeArray reSizeArray(SafeArray oldArr, int M);

#endif
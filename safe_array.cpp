#include "safe_array.h"
#include <iostream>

static int stub_value = -999;

SafeArray createArray(int size) {
    SafeArray result{new int[size]{}, size};
    return result;
}

int& getElement(SafeArray& arr, int index) {
    if (index < 0 || index >= arr.size) {
        std::cerr << "[Ошибка] Индекс " << index << " вне границ [0, " << arr.size - 1 << "].\n";
        return stub_value;
    }
    return arr.data[index];
}

void printSafe(const SafeArray& arr) {
    std::cout << "SafeArray(размер=" << arr.size << "): ";
    for (int i = 0; i < arr.size; ++i) std::cout << arr.data[i] << " ";
    std::cout << "\n";
}

SafeArray reSizeArray(SafeArray oldArr, int M) {
    int* newData = new int[M]{};
    int copyCount = (oldArr.size < M) ? oldArr.size : M;
    for (int i = 0; i < copyCount; ++i) newData[i] = oldArr.data[i];

    if (M < oldArr.size) {
        std::cout << "Удаленные элементы при изменении размера (" << oldArr.size << " -> " << M << "): ";
        for (int i = M; i < oldArr.size; ++i) std::cout << oldArr.data[i] << " ";
        std::cout << "\n";
    }

    delete[] oldArr.data;
    oldArr.data = newData;
    oldArr.size = M;
    return oldArr;
}
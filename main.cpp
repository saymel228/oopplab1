#include <iostream>
#include <ctime>
#include <cstdlib>

// --- ЗАДАНИЕ 1 ---
void fillArray(int (&arr)[10]) {
    for (auto &x : arr) x = std::rand() % 100;
}
void printArray(const int (&arr)[10]) {
    for (const auto &x : arr) std::cout << x << " ";
    std::cout << "\n";
}
void swapElements(int (&arr)[10], size_t i, size_t j) {
    if (i >= 10 || j >= 10) return;
    std::swap(arr[i], arr[j]);
}
void multiplyByTwo(int (&arr)[10]) {
    for (auto &x : arr) x *= 2;
}

int main() {
    setlocale(LC_ALL, "Russian"); 
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // === Выполнение Задания 1 ===
    std::cout << "=== Задание 1: Статический массив ===\n";
    int staticArr[10];
    
    fillArray(staticArr);
    std::cout << "Исходный массив: "; 
    printArray(staticArr);

    swapElements(staticArr, 1, 8);
    std::cout << "После обмена элементов с индексами 1 и 8: "; 
    printArray(staticArr);

    multiplyByTwo(staticArr);
    std::cout << "После умножения каждого элемента на 2: "; 
    printArray(staticArr);

    return 0;
}
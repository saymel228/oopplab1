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

        // ===================== ЗАДАНИЕ 2 =====================
    std::cout << "\n=== Задание 2: Динамический массив ===\n";
    int N;
    std::cout << "Введите размер динамического массива N: ";
    std::cin >> N;

    int* dynArr = new int[N]{};
    std::cout << "Введите " << N << " чисел через Enter:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> dynArr[i];
    }

    auto process = [](int*& arr, int size) {
        int splitIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (arr[i] < 0) { splitIndex = i; break; }
        }

        if (splitIndex != -1 && splitIndex > 0) {
            int* newArr = new int[splitIndex]{};
            for (int i = 0; i < splitIndex; ++i) newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
            std::cout << "Найден отрицательный элемент в индексе " << splitIndex 
                      << ". Новый размер массива: " << splitIndex << ".\n";
        } else {
            std::cout << "Отрицательные элементы не найдены или первый элемент уже отрицательный.\n";
        }
    };

    process(dynArr, N);

    std::cout << "Результатирующий массив: ";
    for (int i = 0; i < N; ++i) { 
        if (dynArr[i] == 0 && i > 0) break; 
        std::cout << dynArr[i] << " "; 
    }
    std::cout << "\n";

    delete[] dynArr;
    dynArr = nullptr;
    std::cout << "Указатель после удаления установлен в: " << dynArr << "\n";

    return 0;
}
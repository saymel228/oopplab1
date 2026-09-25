#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "safe_array.h"
#include "matrix_utils.h"

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

        // ===================== ЗАДАНИЕ 3 =====================
    std::cout << "\n=== Задание 3: Безопасный массив ===\n";
    SafeArray myArr = createArray(5);
    getElement(myArr, 2) = 999;
    std::cout << "Попытка записи по неверному индексу 10:\n";
    getElement(myArr, 10) = 555; 
    printSafe(myArr);
    
    std::cout << "Изменение размера с 5 до 3:\n";
    myArr = reSizeArray(myArr, 3); 
    printSafe(myArr);

    std::cout << "Изменение размера с 3 до 7:\n";
    myArr = reSizeArray(myArr, 7); 
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;
    myArr.size = 0;

        // ===================== ЗАДАНИЕ 4 =====================
    std::cout << "\n=== Задание 4: Матрица оценок студентов ===\n";
    int students = 3, subjects = 4;
    int** grades = allocateMatrix(students, subjects);
    fillMatrix(grades, students, subjects);
    
    std::cout << "\nМатрица с рамкой:\n";
    printMatrix(grades, students, subjects);
    
    std::cout << "\nМатрица без рамки:\n";
    printMatrix(grades, students, subjects, false, "Оценки без рамки");
    
    std::cout << "\nИтоговая ведомость:\n";
    printMatrix(grades, students, subjects, true, "Итоговая ведомость");
    
    freeMatrix(grades, students);

    return 0;
}
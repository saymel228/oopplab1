#include "matrix_utils.h"
#include <iostream>
#include <iomanip>

int** allocateMatrix(int rows, int cols) {
    int** mat = new int*[rows];
    for (int i = 0; i < rows; ++i) mat[i] = new int[cols]{};
    return mat;
}

void fillMatrix(int** matrix, int rows, int cols) {
    std::cout << "Заполнение матрицы оценок (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Введите оценку [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders, const std::string& title) {
    std::cout << "\n--- " << title << " ---\n";
    if (showBorders) {
        std::cout << " "; for (int j = 0; j < cols * 6 + 1; ++j) std::cout << "*";
        std::cout << "\n";
    }
    for (int i = 0; i < rows; ++i) {
        if (showBorders) std::cout << "| ";
        for (int j = 0; j < cols; ++j) std::cout << std::setw(4) << matrix[i][j] << " ";
        if (showBorders) std::cout << "|\n"; else std::cout << "\n";
    }
    if (showBorders) {
        std::cout << " "; for (int j = 0; j < cols * 6 + 1; ++j) std::cout << "*";
        std::cout << "\n";
    }
}
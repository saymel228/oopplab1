#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#include <string>

int** allocateMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);
void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, const std::string& title = "Матрица");

#endif
#ifndef LABA13_MATRIX_H
#define LABA13_MATRIX_H

#include <stdbool.h>
#include <stdio.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int n_rows; // количество рядов
    int n_cols; // количество столбцов
} matrix;
typedef struct position {
    int row_index;
    int col_index;
} position;
// размещает в динамической памяти матрицу размером n_rows на n_cols. Возвращает матрицу.
matrix get_mem_matrix(int n_rows, int n_cols);
// размещает в динамической памяти массив из n_matrices матриц размером n_rows на n_cols.
// Возвращает указатель на нулевую матрицу.
matrix *get_mem_array_of_matrices(int n_matrices, int n_rows, int n_cols);
// освобождает память, выделенную под хранение матрицы m.
void free_mem_matrix(matrix *m);
// освобождает память, выделенную под хранение массива ms из n_matrices матриц.
void free_mem_matrices(matrix *ms, int n_matrices);
// ввод матрицы m.
void input_matrix(matrix *m);
// ввод массива из n_matrices матриц, хранящейся по адресу ms.
void input_matrices(matrix *ms, int n_matrices);
// вывод матрицы m.
void output_matrix(matrix *m);
// вывод массива из n_matrices матриц, хранящейся по адресу ms.
void output_matrices(matrix *ms, int n_matrices);
// обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swap_rows(matrix *m, int i1, int i2);
// обмен колонок с порядковыми номерами j1 и j2 в матрице m.
void swap_columns(matrix *m, int j1, int j2);
// выполняет сортировку вставками строк матрицы m по неубыванию значения функции criteria применяемой для строк.
void insertion_sort_rows_matrix_by_row_criteria(matrix *m, int (*criteria)(int*, int));
// выполняет сортировку выбором столбцов матрицы m по неубыванию значения функции criteria применяемой для столбцов.
void selection_sort_cols_matrix_by_col_criteria(matrix *m, int (*criteria)(int*, int));
// возвращает значение ’истина’, если матрица m является квадратной, ложь – в противном случае.

bool is_square_matrix(matrix *m);
// возвращает значение ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool are_two_matrices_equal(matrix *m1, matrix *m2);
// возвращает значение ’истина’, если матрица m является единичной, ложь – в противном случае.
bool is_e_matrix(matrix *m);
// возвращает значение ’истина’, если матрица m является симметричной, ложь – в противном случае.
bool is_symmetric_matrix(matrix *m);
// транспонирует квадратную матрицу m.
void transpose_square_matrix(matrix *m);
// транспонирует матрицу m.
void transpose_matrix(matrix *m);
// возвращает позицию минимального элемента матрицы m.
position get_min_value_pos(matrix m);
// возвращает позицию максимального элемента матрицы m.
position get_max_value_pos(matrix m);
// возвращает матрицу размера n_rows на n_cols, построенную из элементов массива a.
matrix create_matrix_from_array(const int a[], int n_rows, int n_cols);
// возвращает указатель на нулевую матрицу массива из n_matrices матриц, размещенных
//в динамической памяти, построенных из элементов массива a.
matrix* create_array_of_matrix_from_array(const int values[], size_t n_matrices, size_t n_rows, size_t n_cols);

#endif //LABA13_MATRIX_H
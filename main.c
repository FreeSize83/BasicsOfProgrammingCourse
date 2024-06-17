#include <assert.h>
#include "libs/data_structures/matrix/matrix.h"
void test_swap_rows_different_rows() {
    matrix m1 = create_matrix_from_array((int[]){1, 2,
                                                 3,4}, 2, 2);
    matrix m2 = create_matrix_from_array((int[]){3, 4,
                                                 1,2}, 2, 2);
    swap_rows(&m2, 0, 1);
    assert(are_two_matrices_equal(&m1, &m2));
    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}
void test_swap_rows_different_columns() {
    matrix m1 = create_matrix_from_array((int[]){1, 2,
                                                 3,4}, 2, 2);
    matrix m2 = create_matrix_from_array((int[]){2, 1,
                                                 4,3}, 2, 2);
    swap_columns(&m2, 0, 1);
    assert(are_two_matrices_equal(&m1, &m2));
    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}
void test_swap() {
    test_swap_rows_different_rows();
    test_swap_rows_different_columns();
}
// возвращает сумму элементов массива.
int get_sum(int *a, int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    return res;
}
void test_sort_insertion_sort_rows_different_rows() {
    matrix m1 = create_matrix_from_array((int[]) {2, 3, 4,
                                                  8,9,10,
                                                  5,6,7},3,3);
    matrix m2 = create_matrix_from_array((int[]) {2, 3, 4,
                                                  5,6,7,
                                                  8,9,10},3,3);
    insertion_sort_rows_matrix_by_row_criteria(&m1, get_sum);

    assert(are_two_matrices_equal(&m1, &m2));
    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}
void test_selection_sort_cols_different_columns() {
    matrix m1 = create_matrix_from_array((int[]) {3, 1, 2,
                                                  3,1,2,
                                                  3,1,2},3,3);
    matrix m2 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  1,2,3,
                                                  1,2,3},3,3);
    selection_sort_cols_matrix_by_col_criteria(&m1, get_sum);
    assert(are_two_matrices_equal(&m1, &m2));
    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}
void test_sort() {
    test_sort_insertion_sort_rows_different_rows();
    test_selection_sort_cols_different_columns();
}
void test_square_matrix_is_not_square() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  4,5, 6},2,3);
    assert(!is_square_matrix(&m1));
    free_mem_matrix(&m1);
}
void test_square_matrix_is_square() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  4,5, 6,
                                                  7,8,9},3,3);
    assert(is_square_matrix(&m1));
    free_mem_matrix(&m1);
}
void test_square_matrix() {
    test_square_matrix_is_not_square();
    test_square_matrix_is_square();
}
void test_e_matrix_is_e_matrix() {
    matrix m1 = create_matrix_from_array((int[]) {1, 0, 0,
                                                  0,1, 0,
                                                  0,0,1},3,3);
    assert(is_e_matrix(&m1));
    free_mem_matrix(&m1);
}

void test_e_matrix_is_not_e_matrix() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  0,1, 0,
                                                  0,8,1},3,3);
    assert(!is_e_matrix(&m1));
    free_mem_matrix(&m1);
}
void test_e_matrix() {
    test_e_matrix_is_e_matrix();
    test_e_matrix_is_not_e_matrix();
}
void test_symmetric_matrix_is_not_symmetric() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  4,5, 6,
                                                  7,8,9},3,3);
    assert(!is_symmetric_matrix(&m1));
    free_mem_matrix(&m1);
}
void test_symmetric_matrix_is_symmetric() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  2,1, 5,
                                                  3,5,1},3,3);
    assert(is_symmetric_matrix(&m1));
    free_mem_matrix(&m1);
}
void test_symmetric_matrix() {
    test_symmetric_matrix_is_not_symmetric();
    test_symmetric_matrix_is_symmetric();
}
void test_transpose_matrix_square_matrix() {
    matrix m1 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  4,5,6,
                                                  7,8,9},3,3);
    matrix m2 = create_matrix_from_array((int[]) {1, 4, 7,
                                                  2,5,8,
                                                  3,6,9},3,3);
    transpose_square_matrix(&m2);
    assert(are_two_matrices_equal(&m1, &m2));
    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}
void test_transpose_matrix_not_square(){
    matrix m1 = create_matrix_from_array((int[]) {1, 4,
                                                  2,5,
                                                  3,6},3,2);
    matrix m2 = create_matrix_from_array((int[]) {1, 2, 3,
                                                  13
            ,5,6},2,3);
    transpose_matrix(&m2);
    assert(are_two_matrices_equal(&m1, &m2));
    free_mem_matrix(&m1);
    free_mem_matrix(&m2);
}
void test_transpose_matrix() {
    test_transpose_matrix_square_matrix();
    test_transpose_matrix_not_square();
}
void get_value_get_min_value() {
    matrix m1 = create_matrix_from_array((int[]) {1, 4,
                                                  2,5},2,2);
    position res = get_min_value_pos(m1);
    assert(res.row_index == 0 && res.col_index == 0);
    free_mem_matrix(&m1);
}
void get_value_get_max_value() {
    matrix m1 = create_matrix_from_array((int[]) {1, 4,
                                                  2,5},2,2);
    position res = get_max_value_pos(m1);
    assert(res.row_index == 1 && res.col_index == 1);
    free_mem_matrix(&m1);
}
void test_get_value() {
    get_value_get_min_value();
    get_value_get_max_value();
}
void test() {
    test_swap();
    test_sort();
    test_square_matrix();
    test_e_matrix();
    test_symmetric_matrix();
    test_transpose_matrix();
    test_get_value();
}
int main () {
    test();
}
/*2D array(matrix) is array of arrays.*/
#include <iostream>

int main() {

    int rows, cols;
    std::cout << "Enter the rows and columns of matrix: ";
    std::cin >> rows >> cols;

    //inputing a matrix through traversing
    int mat[rows][cols];
    std::cout << "Enter the elements in " << rows << "x" << cols << " matrix: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> mat[i][j];
        }
    }
    std::cout << "The matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << mat[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    //sum of whole matrix elements
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += mat[i][j];
        }
    }
    std::cout << "Sum of matrix: " << sum << "\n\n";
    //sum of primary and secondary diagonals in matrix
    int priSum = 0, secSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //primary diagonal sum
            if (i == j) {
                priSum += mat[i][j];
            }
            //secondary diagonal sum
            if ((i + j) == (rows - 1)) {
                secSum += mat[i][j];
            }
        }
    }
    std::cout << "Primary diagonal sum: " << priSum << "\tSecondary diagonal sum: " << secSum << "\n\n";
    //find maximum element in matrix
    int max = mat[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //compare
            if (max < mat[i][j]) {
                max = mat[i][j];
            }
        }
    }
    std::cout << "Largest element in matrix: " << max << "\n\n";
    return 0;
}
#include <stdio.h>

int main() {
    // Assume 4x5 sparse matrix
    int sparseMatrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };

    int size = 0;

    // Count non-zero elements
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0)
                size++;
        }
    }

    // Declare compactMatrix with 3 rows and 'size' columns
    int compactMatrix[3][size];

    // Fill compactMatrix with row, column, and value information
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (sparseMatrix[i][j] != 0) {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    // Print the compact matrix
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", compactMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
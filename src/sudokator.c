#include <stdio.h>

int sudoku[9][9];

void setNumber(int row, int column, int value) {
    sudoku[row][column] = value;
}

int getNumber(int row, int column) {
    return sudoku[row][column];
}

void printSudoku() {
    printf("+-----------------------------+\n");
    printf("| x  x  x |         |         |\n");
    printf("| x  x  x |         |         |\n");
    printf("| x  x  x |         |         |\n");
    printf("+-----------------------------+\n");
    printf("|         |         |         |\n");
    printf("|         |         |         |\n");
    printf("|         |         |         |\n");
    printf("+-----------------------------+\n");
    printf("|         |         |         |\n");
    printf("|         |         |         |\n");
    printf("|         |         |         |\n");
    printf("+-----------------------------+\n");
}

int main() {
    int i = 0;
    int j = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            setNumber(i, j, 0);
        }
    }

    printSudoku();
    return 0;
}

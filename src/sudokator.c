#include <stdio.h>

int sudoku[9][9];

void setNumber(int row, int column, int value) {
    sudoku[row][column] = value;
}

int getNumber(int row, int column) {
    return sudoku[row][column];
}

int printSudokuRow(int row) {
    printf("| ");

    int column;
    for(column = 0; column < 9; column++) {
        printf("%d", sudoku[row][column]);

        if(column < 8) {
            char *separator = ((column == 2 || column == 5) ? " | " : "  ");
            printf("%s", separator);
        }
    }

    printf(" |\n");
}

void printSudoku() {
    printf("+-----------------------------+\n");
    printSudokuRow(0);
    printSudokuRow(1);
    printSudokuRow(2);
    printf("+-----------------------------+\n");
    printSudokuRow(3);
    printSudokuRow(4);
    printSudokuRow(5);
    printf("+-----------------------------+\n");
    printSudokuRow(6);
    printSudokuRow(7);
    printSudokuRow(8);
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

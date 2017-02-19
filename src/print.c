#include <stdio.h>
#include "print.h"

extern SudokuCell sudoku[9][9];

int printSudokuRow(int row) {
    printf("| ");

    int column;
    for(column = 0; column < 9; column++) {
        printf("%d", sudoku[row][column].value);

        if(column < 8) {
            char *separator = ((column == 2 || column == 5) ? " | " : "  ");
            printf("%s", separator);
        }
    }

    printf(" |\n");
}

void printSudoku() {
    int row;

    for(row = 0; row < 9; row++) {
        if (row % 3 == 0) {
            printf("+-----------------------------+\n");
        }

        printSudokuRow(row);
    }

    printf("+-----------------------------+\n");
}

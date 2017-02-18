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
    int row;

    for(row = 0; row < 9; row++) {
        if (row % 3 == 0) {
            printf("+-----------------------------+\n");
        }

        printSudokuRow(row);
    }
    
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

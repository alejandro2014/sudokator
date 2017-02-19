#include "init.h"
#include "print.h"
#include "sudokator.h"

SudokuCell sudoku[9][9];

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

void discardValue(int row, int column, int value) {
    //printf("value = %d cell.value = %d cell.options[value] = %d\n", value, cell.value, cell.options[value]);

    if(sudoku[row][column].value == 0 && sudoku[row][column].options[value] == FALSE) {
        printf("Discarding value %d in [%d][%d]\n", value, row, column);
        sudoku[row][column].options[value] = TRUE;
        sudoku[row][column].optionsNo--;
    }
}

void checkRow(int row, int value) {
    int i;

    for(i = 0; i < 9; i++) {
        discardValue(row, i, value);
    }
}

void checkColumn(int column, int value) {
    int i;

    for(i = 0; i < 9; i++) {
        discardValue(i, column, value);
    }
}

int getGroupCoord(int cellCoord) {
    if(cellCoord < 3) return 0;
    if(cellCoord < 6) return 3;
    if(cellCoord < 9) return 6;
}

void checkSquare(int row, int column, int value) {
    int iniCoordI = getGroupCoord(row);
    int iniCoordJ = getGroupCoord(column);
    int i, j;

    for(i = iniCoordI; i < iniCoordI + 3; i++) {
        for(j = iniCoordJ; j < iniCoordJ + 3; j++) {
            discardValue(i, j, value);
        }
    }
}

void setNumber(int row, int column, int value) {
    sudoku[row][column].value = value;

    checkRow(row, value);
    checkColumn(column, value);
    checkSquare(row, column, value);
}

int getNumber(int row, int column) {
    return sudoku[row][column].value;
}

void initOptions() {
    int row, column;

    for(row = 0; row < 9; row++) {
        for(column = 0; column < 9; column++) {
            if(getNumber(row, column) == 0) {
                sudoku[row][column].optionsNo = 9;
            }
        }
    }
}

void initSudoku() {
    initOptions();
    initValues();
}

void printOptions() {
    int row, column;

    for(row = 0; row < 9; row++) {
        for(column = 0; column < 9; column++) {
            if(sudoku[row][column].value == 0) {
                printf("%d ", sudoku[row][column].optionsNo);
            } else {
                printf("x ");
            }
        }

        printf("\n");
    }
}

void findFirstUniqueOption(int *optionCoords) {
    int i, j;

    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            if(sudoku[i][j].value == 0 && sudoku[i][j].optionsNo == 1) {
                *(optionCoords + 0) = i;
                *(optionCoords + 1) = j;
                return;
            }
        }
    }
}

void completeUniqueOption(int *optionCoords) {
    int row = *(optionCoords + 0);
    int column = *(optionCoords + 1);
    SudokuCell cell = sudoku[row][column];
    int currentValue;

    for(currentValue = 0; currentValue < 9; currentValue++) {
        /*printf(">> [%d][%d] = %d - ", row, column, currentValue);
        printf("%d ", sudoku.options[currentValue]);
        printf("\n");*/
        if(cell.options[currentValue] == FALSE) {
            printf(">> [%d][%d] = %d\n", row, column, currentValue + 1);
            sudoku[row][column].value = currentValue + 1;
            cell.options[currentValue] == TRUE;
            return;
        }
    }
}

int main() {
    int optionCoords[2];

    initSudoku();
    printSudoku();
    printOptions();

    /*findFirstUniqueOption(&optionCoords[0]);
    printf("First unique option: [%d][%d]\n", optionCoords[0], optionCoords[1]);
    completeUniqueOption(&optionCoords[0]);

    checkRow(optionCoords[0], optionCoords[1]);
    checkColumn(optionCoords[0], optionCoords[1]);
    checkSquare(optionCoords[0], optionCoords[1]);

    printSudoku();
    printOptions();*/

    return 0;
}

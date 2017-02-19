#include "init.h"
#include "print.h"
#include "sudokator.h"

int sudoku[9][9];
Options options[9][9];

void setNumber(int row, int column, int value) {
    sudoku[row][column] = value;
}

int getNumber(int row, int column) {
    return sudoku[row][column];
}

void markValue(int row, int column, int value) {
    if(value != 0 && options[row][column].array[value] == FALSE) {
        options[row][column].array[value] = TRUE;
        options[row][column].optionsNo--;
    }
}

int getGroupCoord(int cellCoord) {
    if(cellCoord < 3) return 0;
    if(cellCoord < 6) return 1;
    if(cellCoord < 9) return 2;
}

void checkRow(int row, int column) {
    int i;

    for(i = 0; i < 9; i++) {
        markValue(row, column, sudoku[row][i]);
    }
}

void checkColumn(int row, int column) {
    int i;

    for(i = 0; i < 9; i++) {
        markValue(row, column, sudoku[i][column]);
    }
}

void checkSquare(int row, int column) {
    int i = getGroupCoord(row);
    int j = getGroupCoord(column);
    int iniCoordI = 3 * i;
    int iniCoordJ = 3 * j;
    int currentI, currentJ;

    for(currentI = iniCoordI; currentI < iniCoordI + 3; currentI++) {
        for(currentJ = iniCoordJ; currentJ < iniCoordJ + 3; currentJ++) {
            markValue(row, column, sudoku[currentI][currentJ]);
        }
    }
}

void initOptions() {
    int row, column;

    for(row = 0; row < 9; row++) {
        for(column = 0; column < 9; column++) {
            if(getNumber(row, column) == 0) {
                options[row][column].optionsNo = 9;

                checkRow(row, column);
                checkColumn(row, column);
                checkSquare(row, column);
            }
        }
    }
}

void initSudoku() {
    initValues();
    initOptions();
}

void printOptions() {
    int row, column;

    for(row = 0; row < 9; row++) {
        for(column = 0; column < 9; column++) {
            if(sudoku[row][column] == 0) {
                printf("[%d][%d] = %d\n", row, column, options[row][column].optionsNo);
            }
        }
    }
}

int main() {
    initSudoku();
    printSudoku();
    printOptions();
    return 0;
}

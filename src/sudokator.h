#ifndef SUDOKATOR_H
#define SUDOKATOR_H

#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define BOOLEAN int

typedef struct {
    int value;
    int optionsNo;
    BOOLEAN options[9];
} SudokuCell;

int printSudokuRow(int row);

void printSudoku();

void discardValue(int row, int column, int value);

void checkRow(int row, int value);

void checkColumn(int column, int value);

int getGroupCoord(int cellCoord);

void checkSquare(int row, int column, int value);

void setNumber(int row, int column, int value);

int getNumber(int row, int column);

void initOptions();

void initSudoku();

void printOptions();

void findFirstUniqueOption(int *optionCoords);

void completeUniqueOption(int *optionCoords);


#endif

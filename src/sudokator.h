#ifndef SUDOKATOR_H
#define SUDOKATOR_H

#include <stdio.h>

#define FALSE 0
#define TRUE 1
#define BOOLEAN int

typedef struct {
    int optionsNo;
    BOOLEAN array[9];
} Options;

void setNumber(int row, int column, int value);

int getNumber(int row, int column);

void checkRow(int row, int column);

void checkColumn(int row, int column);

void checkSquare(int row, int column);

void initSudoku();

#endif

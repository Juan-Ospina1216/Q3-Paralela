#ifndef __HOTPLATE_H__
#define __HOTPLATE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Constants
#define MAXROW 10000
#define MAXCOL 10000
// funciones
void initialize(float arr[][MAXCOL], int row, int col);
void new_values(float arr2[][MAXCOL], float arr1[][MAXCOL], int row, int col);
int check_convergence(float arr[][MAXCOL], int row, int col);
double step();

#endif // hotplateb.h
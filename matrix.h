#ifndef matrix_hpp
#define matrix_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

class Matrix{
public:
    Matrix();
    void generuj(Matrix*,int,int);
    void deleteM(Matrix *m);
    void show();
    void showVis();
    void searchFor(int,int,int,int);
    int **tab;
    int **visited;
    int **checked;
    int row,col;
    int currentCol;
    void add(int,int,int);
    void colorCount(int x, int y, int input, int &count);
    int compLogic();

};

void play(Matrix*,int,int);
void show();
#endif

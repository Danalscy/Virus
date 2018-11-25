#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "matrix.h"

Matrix::Matrix(){

}
void Matrix::add(int x,int y,int value){
    visited[x][y]=value;
}
void Matrix::generuj(Matrix *m,int r, int c){
    m->row = r;
    m->col = c;
    m->tab= new int*[r];
    m->visited= new int*[r];
    m->checked= new int*[r];
    for(int i = 0; i < r; ++i) {
        m->tab[i] = new int[c];
        m->visited[i] = new int[c];
        m->checked[i]= new int[c];
    }
    srand(time(NULL));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int liczba = std::rand()%5;
            m->tab[i][j]=liczba;
            m->visited[i][j]=0;
            m->checked[i][j]=0;
        }
    }
    while(m->tab[0][0]==m->tab[0][1]){
        int liczba = std::rand()%5;
        m->tab[0][1]=liczba;
    }
    while(m->tab[0][0]==m->tab[1][0]){
        int liczba = std::rand()%5;
        m->tab[1][0]=liczba;
    }
    while(m->tab[m->row-1][m->col-1]==m->tab[m->row-1][m->col-2]){
        int liczba = std::rand()%5;
        m->tab[m->row-1][m->col-2]=liczba;
    }
    while(m->tab[m->row-1][m->col-1]==m->tab[m->row-2][m->col-1]){
        int liczba = std::rand()%5;
        m->tab[m->row-2][m->col-1]=liczba;
    }

    m->visited[0][0]=1;
    m->visited[r-1][c-1]=2;
    //m->currentCol=m->tab[0][0];
}
void Matrix::deleteM(Matrix *m){

    for(int i = 0; i < m->row; ++i) {
        delete m->tab[i];
        delete m->visited[i];
        delete m->checked[i];
    }
    delete m->tab;
    delete m->visited;
    delete m->checked;
}


void Matrix::show(){
     //printf("currentCol : %d\n",currentCol);
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf(" %d  ",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Matrix::showVis(){
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf(" %d  ",visited[i][j]);
        }
        printf("\n");
    }
}
void play(Matrix *m, int in, int who){
    m->currentCol=in;
    for(int i=0;i<m->row;i++){
        for(int j=0;j<m->col;j++){
            if(m->visited[i][j]==who){
                //printf("Visited: %d %d\n",i,j);
                m->searchFor(i,j,in,who);
            }
        }
    }
    m->show();
    m->showVis();
}
void Matrix::searchFor(int x, int y, int input, int who){
        int r[] = {-1,0,0,1};
        int c[] = {0,-1,1,0};
        visited[x][y]=who;
        tab[x][y]=input;
        for (int i = 0; i < 4; i++) {
            int R = x + r[i];
            int C = y + c[i];
            if (R >= 0 && C >= 0 && R < row && C < col && visited[R][C]==0){
                if (tab[R][C] == input) {
                    searchFor(R, C,input, who);
                }
            }
        }
}

void Matrix::colorCount(int x, int y, int input, int &count){
    int r[] = {-1,0,0,1};
    int c[] = {0,-1,1,0};
    checked[x][y]=1;
    for (int i = 0; i < 4; i++) {
        int R = x + r[i];
        int C = y + c[i];
        if (R >= 0 && C >= 0 && R < row && C < col && visited[R][C]==0 && checked[R][C]==0){

            if (tab[R][C] == input) {
                count++;
                colorCount(R, C,input,count);
            }
        }
    }
}



int Matrix::compLogic(){
    int count[4], countC, which;

    for(int k=0;k<5;k++){
        count[k]=0;
        countC=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(visited[i][j]==2){
                colorCount(i,j,k,countC);

            }
        }
    }
    count[k]=countC;
    }
    which=0;
    countC=0;
    for(int i=0;i<5;i++){
        if(count[i]>countC){
            countC=count[i];
            which=i;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            checked[i][j]=0;
        }
    }

    return which;
}

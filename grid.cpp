#include "grid.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Grid::Grid(QObject *parent) : QObject(parent)
{
    srand(time(NULL));
    Grille = new Cell*[4];
    for (int i=0; i>4; i++){
        Grille[i] = new Cell[4];
    }
    for(int k=0;k<2;k++){
        int i = rand()%4;;
        int j = rand()%4;;
        Grille[i][j].increment(1);
    }
}

QString Grid::readScore(){
    return score.readCompteur();
}

Grid::~Grid() {
    for (int i=0; i<4; i++){
        delete [] Grille[i];
    }
    delete [] Grille;
}

void Grid::generer(){
    srand(time(NULL));
    float l = rand();
    int k;
    if (l>0.25){
        k=1;
    }
    else {k=2;}
    int b=0;
    while(b==0){
        int i = rand()%4;;
        int j = rand()%4;;
        if (Grille[i][j].getValue()==0){
            b=1;
            Grille[i][j].setValue(k);

        }
    }

}

bool Grid::defaite(){
    bool a =true ;
    {int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(Grille[i][j].getValue()!=0){a=false;}
            }
        }}
    return a;
}

int Grid::read(int i, int j){
    return Grille[i][j].getValue();
}


void Grid::up()
{
for (int j=0;j<4;j++){
    for(int i=1; i<4; i++){
        if (Grille[i][j].getValue()!=0){
            int k=i-1;
            while(k>0 && Grille[k][j].getValue()==0){
                k--;
            }
            if (k==0 && Grille[k][j].getValue()==0){
                Grille[0][j].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if ((k+1)!=i && Grille[i][j].getValue()!=Grille[k][j].getValue()){
                Grille[k+1][j].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if (k!=i && Grille[i][j].getValue()==Grille[k][j].getValue()){
                Grille[k][j].setValue(Grille[i][j].getValue()+1);
                Grille[i][j].setValue(0);
                score.increment(Grille[i][j].getValue());
            }

        }

    }
}

}

void Grid::down()
{
for (int j=0;j<4;j++){
    for(int i=2; i>-1; i--){
        if (Grille[i][j].getValue()!=0){
            int k=i+1;
            while(k<3 && Grille[k][j].getValue()==0){
                k++;
            }
            if (k==3 && Grille[k][j].getValue()==0){
                Grille[k][j].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if ((k-1)!=i && Grille[i][j].getValue()!=Grille[k][j].getValue()){
                Grille[k-1][j].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if (k!=i && Grille[i][j].getValue()==Grille[k][j].getValue()){
                Grille[k][j].setValue(Grille[i][j].getValue()+1);
                Grille[i][j].setValue(0);
                score.increment(Grille[i][j].getValue());
            }

        }

    }
}

}

void Grid::left()
{
for (int i=0;i<4;i++){
    for(int j=1; j<4; j++){
        if (Grille[i][j].getValue()!=0){
            int k=j-1;
            while(k>0 && Grille[k][j].getValue()==0){
                k--;
            }
            if (k==0){
                Grille[i][k].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if ((k+1)!=j && Grille[i][j].getValue()!=Grille[i][k].getValue()){
                Grille[i][k+1].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if (k!=j && Grille[i][j].getValue()==Grille[i][k].getValue()){
                Grille[k][j].setValue(Grille[i][j].getValue()+1);
                Grille[i][j].setValue(0);
                score.increment(Grille[i][j].getValue());
            }

        }

    }
}

}

void Grid::rigth()
{
for (int i=0;i<4;i++){
    for(int j=3; j>-1; j--){
        if (Grille[i][j].getValue()!=0){
            int k=j+1;
            while(k<3 && Grille[i][k].getValue()==0){
                k--;
            }
            if (k==3){
                Grille[i][k].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if ((k-1)!=j && Grille[i][j].getValue()!=Grille[i][k].getValue()){
                Grille[k+1][j].setValue(Grille[i][j].getValue());
                Grille[i][j].setValue(0);
            }
            if (k!=j && Grille[i][j].getValue()==Grille[i][k].getValue()){
                Grille[i][k].setValue(Grille[i][j].getValue()+1);
                Grille[i][j].setValue(0);
                score.increment(Grille[i][j].getValue());
            }

        }

    }
}

}


bool Grid::estegal (const Grid &G,const Grid &D){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(D.Grille[i][j].getValue()!=G.Grille[i][j].getValue()){return false;}
        }}
    return true;
}

void Grid::copy (Grid &G,const Grid &D){
    if ( &D != &G) {
        for(int i=0; i<4; i++)
            for(int j=0; j<4; j++)
                G.Grille[i][j] = D.Grille[i][j];
    }

}

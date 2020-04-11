#include "grid.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Grid::Grid(int a)
{srand(time(NULL));
    {int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                Grille[i][j]=a;
            }
        }}
    for(int k=0;k<2;k++){
        int i = rand()%4;;
        int j = rand()%4;;
        Grille[i][j]=1;
    }
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
        if (Grille[i][j]==0){
            b=1;
            Grille[i][j]=k;

        }
    }

}

bool Grid::defaite(){
    bool b =true ;
    for(int a=0;a<4;a++){
        b=b&&mvtinutile(a);
    }
    return b;
}

int Grid::read(int i, int j){
    return Grille [i][j];
}

bool Grid::estegal (const Grid &G,const Grid &D){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(D.Grille[i][j]!=G.Grille[i][j]){return false;}
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


bool Grid::mvtinutile(int a){
    if (a==0){
        Grid G(0);
        copy(G,*this);
        G.Up();
        return estegal(G,*this);
        }
    if (a==1){
        Grid G(0);
        copy(G,*this);
        G.Down();
        return estegal(G,*this);
        }
    if (a==2){
        Grid G(0);
        copy(G,*this);
        G.Left();
        return estegal(G,*this);
        }
    if (a==3){
        Grid G(0);
        copy(G,*this);
        G.Rigth();
        return estegal(G,*this);
        }
    return true;
    }



void Grid::Up()
{
for (int j=0;j<4;j++){
    for(int i=1; i<4; i++){
        if (Grille[i][j]!=0){
            int k=i-1;
            while(k>0 && Grille[k][j]==0){
                k--;
            }
            if (k==0 && Grille[k][j]==0){
                Grille[0][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k+1)!=i && Grille[i][j]!=Grille[k][j]){
                Grille[k+1][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=i && Grille[i][j]==Grille[k][j]){
                Grille[k][j]= Grille[i][j]+1;
                Grille[i][j]=0;
                score.increment(Grille[i][j]);
            }

        }

    }
}

}

void Grid::Down()
{
for (int j=0;j<4;j++){
    for(int i=2; i>-1; i--){
        if (Grille[i][j]!=0){
            int k=i+1;
            while(k<3 && Grille[k][j]==0){
                k++;
            }
            if (k==3 && Grille[k][j]==0){
                Grille[k][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k-1)!=i && Grille[i][j]!=Grille[k][j]){
                Grille[k-1][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=i && Grille[i][j]==Grille[k][j]){
                Grille[k][j]= Grille[i][j]+1;
                Grille[i][j]=0;
                score.increment(Grille[i][j]);
            }

        }

    }
}

}

void Grid::Left()
{
for (int i=0;i<4;i++){
    for(int j=1; j<4; j++){
        if (Grille[i][j]!=0){
            int k=j-1;
            while(k>0 && Grille[k][j]==0){
                k--;
            }
            if (k==0){
                Grille[i][k]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k+1)!=j && Grille[i][j]!=Grille[i][k]){
                Grille[i][k+1]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=j && Grille[i][j]==Grille[i][k]){
                Grille[k][j]= Grille[i][j]+1;
                Grille[i][j]=0;
                score.increment(Grille[i][j]);
            }

        }

    }
}

}

void Grid::Rigth()
{
for (int i=0;i<4;i++){
    for(int j=3; j>-1; j--){
        if (Grille[i][j]!=0){
            int k=j+1;
            while(k<3 && Grille[i][k]==0){
                k--;
            }
            if (k==3){
                Grille[i][k]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k-1)!=j && Grille[i][j]!=Grille[i][k]){
                Grille[k+1][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=j && Grille[i][j]==Grille[i][k]){
                Grille[i][k]= Grille[i][j]+1;
                Grille[i][j]=0;
                score.increment(Grille[i][j]);
            }

        }

    }
}

}

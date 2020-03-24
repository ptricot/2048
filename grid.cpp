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
    bool a =true ;
    {int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(Grille[i][j]!=0){a=false;}
            }
        }}
    return a;
}

int Grid::read(int i, int j){
    return Grille [i][j];
}


void Grid::Up()
{
for (int j=0;j<4;j++){
    for(int i=0; i<4; i++){
        if (Grille[i][j]!=0){
            int k=i;
            while(k>-1 && Grille[k][j]==0){
                k--;
            }
            if (k==0){
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
            }

        }

    }
}

}

void Grid::Down()
{
for (int j=0;j<4;j++){
    for(int i=3; i>-1; i--){
        if (Grille[i][j]!=0){
            int k=i;
            while(k<4 && Grille[k][j]==0){
                k++;
            }
            if (k==4){
                Grille[0][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k-1)!=i && Grille[i][j]!=Grille[k][j]){
                Grille[k-1][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=i && Grille[i][j]==Grille[k][j]){
                Grille[k][j]= Grille[i][j]+1;
                Grille[i][j]=0;
            }

        }

    }
}

}

void Grid::Left()
{
for (int i=0;i<4;i++){
    for(int j=3; j>-1; j--){
        if (Grille[i][j]!=0){
            int k=j;
            while(k<4 && Grille[k][j]==0){
                k++;
            }
            if (k==4){
                Grille[0][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k-1)!=j && Grille[i][j]!=Grille[k][j]){
                Grille[k-1][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=j && Grille[i][j]==Grille[k][j]){
                Grille[k][j]= Grille[i][j]+1;
                Grille[i][j]=0;
            }

        }

    }
}

}

void Grid::Rigth()
{
for (int i=0;i<4;i++){
    for(int j=0; j<4; j++){
        if (Grille[i][j]!=0){
            int k=j;
            while(k>-1 && Grille[k][j]==0){
                k--;
            }
            if (k==0){
                Grille[0][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if ((k+1)!=j && Grille[i][j]!=Grille[k][j]){
                Grille[k+1][j]= Grille[i][j];
                Grille[i][j]=0;
            }
            if (k!=j && Grille[i][j]==Grille[k][j]){
                Grille[k][j]= Grille[i][j]+1;
                Grille[i][j]=0;
            }

        }

    }
}

}

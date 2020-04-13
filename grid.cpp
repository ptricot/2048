#include "grid.h"
#include "math.h"
#include <iostream>
using namespace std;

grid::grid(QObject *parent) : QObject(parent)
{
    score = 0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            Grille[i][j]=0;
        }
    }
    generer();
    generer();
    update();
}
void grid::up() {
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
                    score+=Grille[i][j];
                }

            }

        }
    }
    update();
}
void grid::down() {
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
                    score+=Grille[i][j];
                }

            }

        }
    }
    update();
}
void grid::left() {
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
                    score+=Grille[i][j];
                }

            }

        }
    }
    update();
}
void grid::right() {
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
                    score+=Grille[i][j];
                }

            }

        }
    }
    update();
}
void grid::generer(){
    if (!defaite()){
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
}
bool grid::defaite(){
    bool a =true ;
    {int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(Grille[i][j]!=0){a=false;}
            }
        }}
    return a;
}
int grid::readValue(int i, int j){
    if (Grille[i][j]==0){return 0;}
    else {return pow(2,Grille[i][j]);}
}
QString grid::readScore() {
    return QString::number(score);
}

QString grid::read1x1() {
    return QString::number(readValue(0,0));
}
QString grid::read1x2() {
    return QString::number(readValue(0,1));
}
QString grid::read1x3() {
    return QString::number(readValue(0,2));
}
QString grid::read1x4() {
    return QString::number(readValue(0,3));
}
QString grid::read2x1() {
    return QString::number(readValue(1,0));
}
QString grid::read2x2() {
    return QString::number(readValue(1,1));
}
QString grid::read2x3() {
    return QString::number(readValue(1,2));
}
QString grid::read2x4() {
    return QString::number(readValue(1,3));
}
QString grid::read3x1() {
    return QString::number(readValue(2,0));
}
QString grid::read3x2() {
    return QString::number(readValue(2,1));
}
QString grid::read3x3() {
    return QString::number(readValue(2,2));
}
QString grid::read3x4() {
    return QString::number(readValue(2,3));
}
QString grid::read4x1() {
    return QString::number(readValue(3,0));
}
QString grid::read4x2() {
    return QString::number(readValue(3,1));
}
QString grid::read4x3() {
    return QString::number(readValue(3,2));
}
QString grid::read4x4() {
    return QString::number(readValue(3,3));
}
void grid::coutGrid() { // Pour les tests
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout<<Grille[i][j]<<' ';
        }
        cout<<endl;
    }
}

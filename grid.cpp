#include "grid.h"
#include "math.h"
#include <iostream>
#include <fstream>

#ifdef _WIN32
    #include <windows.h>

    void toSleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void toSleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif

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

bool grid::defaite(){
    bool b =true ;
    for(int a=0;a<4;a++){
        b=b&&mvtinutile(a);
    }
    if (b){cout<<"partie terminee";}
    return b;
}

bool grid::estegal (const grid &G){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(Grille[i][j]!=G.Grille[i][j]){return false;}

        }}
    return true;
}


bool grid::mvtinutile(int a){
    grid G;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            G.Grille[i][j] = Grille[i][j];
    if (a==0){
        G.up();
        return estegal(G);
        }
    if (a==1){
        G.down();
        return estegal(G);
        }
    if (a==2){
        G.left();
        return estegal(G);
        }
    if (a==3){
        G.right();
        return estegal(G);
        }
    return true;
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
                    score+=pow(2,Grille[k][j]);
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
                    score+=pow(2,Grille[k][j]);
                }

            }

        }
    }

    update();

    }
void grid::right() {
    for (int i=0;i<4;i++){
        for(int j=2; j>-1; j--){
            if (Grille[i][j]!=0){
                int k=j+1;
                while(k<3 && Grille[i][k]==0){
                    k++;
                }
                if (k==3 && Grille[i][k]==0){
                    Grille[i][k]= Grille[i][j];
                    Grille[i][j]=0;
                }
                if ((k-1)!=j && Grille[i][j]!=Grille[i][k]){
                    Grille[i][k-1]= Grille[i][j];
                    Grille[i][j]=0;
                }
                if (k!=j && Grille[i][j]==Grille[i][k]){
                    Grille[i][k]= Grille[i][j]+1;
                    Grille[i][j]=0;
                    score+=pow(2,Grille[i][k]);
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
                while(k>0 && Grille[i][k]==0){
                    k--;
                }
                if (k==0 && Grille[i][k]==0){
                    Grille[i][0]= Grille[i][j];
                    Grille[i][j]=0;
                }
                if ((k+1)!=j && Grille[i][j]!=Grille[i][k]){
                    Grille[i][k+1]= Grille[i][j];
                    Grille[i][j]=0;
                }
                if (k!=j && Grille[i][j]==Grille[i][k]){
                    Grille[i][k]= Grille[i][j]+1;
                    Grille[i][j]=0;
                    score+=pow(2,Grille[i][k]);
                }

            }

        }
    }

    update();

}

void grid::sleep(){
    toSleep(500);
}
void grid::generer(){

    if (libre()){
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
bool grid::libre(){
    bool a =false ;
    {int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(Grille[i][j]==0){a=true;}
            }
        }}
    return a;
}
QString grid::readValue(int i, int j){
    if (Grille[i][j]==0){return QString::fromStdString("");}
    else {return QString::number(pow(2,Grille[i][j]));}
}
QString grid::readScore() {
    return QString::number(score);
}

QString grid::read1x1() {
    return readValue(0,0);
}
QString grid::read1x2() {
    return readValue(0,1);
}
QString grid::read1x3() {
    return readValue(0,2);
}
QString grid::read1x4() {
    return readValue(0,3);
}
QString grid::read2x1() {
    return readValue(1,0);
}
QString grid::read2x2() {
    return readValue(1,1);
}
QString grid::read2x3() {
    return readValue(1,2);
}
QString grid::read2x4() {
    return readValue(1,3);
}
QString grid::read3x1() {
    return readValue(2,0);
}
QString grid::read3x2() {
    return readValue(2,1);
}
QString grid::read3x3() {
    return readValue(2,2);
}
QString grid::read3x4() {
    return readValue(2,3);
}
QString grid::read4x1() {
    return readValue(3,0);
}
QString grid::read4x2() {
    return readValue(3,1);
}
QString grid::read4x3() {
    return readValue(3,2);
}
QString grid::read4x4() {
    return readValue(3,3);
}
void grid::coutGrid() { // Pour les tests
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            cout<<Grille[i][j]<<' ';
        }
        cout<<endl;
    }
}

void grid::save(){
    ofstream fichier("sauvegarde.txt", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert

            if(fichier)
            {
                for(int i=0;i<4;i++){
                    for(int j=0;j<4;j++){
                        fichier << Grille[i][j]<<endl;
                    }
                }
                    cerr << "Sauvegarde reussie" << endl;
                   fichier.close();
            }
            else
                    cerr << "Impossible d'ouvrir le fichier !" << endl;
    }


void grid::charge(){

    string mon_fichier = "sauvegarde.txt";
         ifstream fichier(mon_fichier.c_str(), ios::in);
            if (fichier)
            {

                    string ligne;
                    int i=0;
                    int j=0;
                    while(getline(fichier,ligne)){
                        int ia =  atoi(ligne.c_str());
                        Grille[i][j]=ia;
                        j++;
                        if(j==4){
                            i++;
                            j=0;
                        }



                    }
                    update();
                    fichier.close();
                    cerr << "Partie chargee" << endl;
            }
            else  // sinon
                    cerr << "Impossible de charger une partie" << endl;

}
QString grid::readColor(int i, int j){
    int val=Grille[i][j];
    switch (val){
        case 0:
            return QString::fromStdString("#fdfdfd");
            break;
        case 1:
            return QString::fromStdString("#fbebe8");
            break;
        case 2:
            return QString::fromStdString("#f4e2df");
            break;
        case 3:
            return QString::fromStdString("#f3a86c");
            break;
        case 4:
            return QString::fromStdString("#fb833a");
            break;
        case 5:
            return QString::fromStdString("#fb743a");
            break;
        case 6:
            return QString::fromStdString("#fb573a");
            break;
        case 7:
            return QString::fromStdString("#fbdc7c");
            break;
        case 8:
            return QString::fromStdString("#fcd65f");
            break;
        case 9:
            return QString::fromStdString("#fbcf45");
            break;
        case 10:
            return QString::fromStdString("#fcc824");
            break;
        case 11:
            return QString::fromStdString("#fec100");
            break;
        case 12:
            return QString::fromStdString("#59c13a");
            break;
    }
    return QString::fromStdString("#59c13a");
}

QString grid::color1x1(){
    return readColor(0,0);
}
QString grid::color1x2(){
    return readColor(0,1);
}
QString grid::color1x3(){
    return readColor(0,2);
}
QString grid::color1x4(){
    return readColor(0,3);
}
QString grid::color2x1(){
    return readColor(1,0);
}
QString grid::color2x2(){
    return readColor(1,1);
}
QString grid::color2x3(){
    return readColor(1,2);
}
QString grid::color2x4(){
    return readColor(1,3);
}
QString grid::color3x1(){
    return readColor(2,0);
}
QString grid::color3x2(){
    return readColor(2,1);
}
QString grid::color3x3(){
    return readColor(2,2);
}
QString grid::color3x4(){
    return readColor(2,3);
}
QString grid::color4x1(){
    return readColor(3,0);
}
QString grid::color4x2(){
    return readColor(3,1);
}
QString grid::color4x3(){
    return readColor(3,2);
}
QString grid::color4x4(){
    return readColor(3,3);
}






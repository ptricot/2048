#ifndef GRID_H
#define GRID_H
#include"cell.h"
#include"compteur.h"

class Grid
{
public:
    Grid(int a);
    void Up();
    void Down();
    void Left();
    void Rigth();
    int read(int i, int j);
    void generer();
    bool defaite();

private :
    int Grille[4][4];
    Compteur score;
};

#endif // GRID_H

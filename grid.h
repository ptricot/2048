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

    bool estegal  (const Grid &G,const Grid &D);
    void copy (Grid &G,const Grid &D);
    bool mvtinutile(int a);

private :
    int Grille[4][4];
    Compteur score;
};

#endif // GRID_H

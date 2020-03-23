#ifndef GRID_H
#define GRID_H


class Grid
{
public:
    Grid();
    void Up();
    void Down();
    void Left();
    void Rigth();
private :
    int Grille[4][4];
};

#endif // GRID_H

#ifndef GRID_H
#define GRID_H
#include"cell.h"
#include"compteur.h"
#include <QObject>

class Grid : public QObject
{
    Q_OBJECT
public:
    explicit Grid(QObject *parent = nullptr);
    ~Grid();
    Q_PROPERTY(QString cptQML READ readScore NOTIFY cptChanged)
    QString readScore();
    Q_INVOKABLE void up();
    Q_INVOKABLE void down();
    Q_INVOKABLE void left();
    Q_INVOKABLE void rigth();
    int read(int i, int j);
    void generer();
    bool defaite();
    Cell **Grille;

    bool estegal  (const Grid &G,const Grid &D);
    void copy (Grid &G,const Grid &D);
    bool mvtinutile(int a);

private :
    Compteur score;
signals:
    void cptChanged();
};

#endif // GRID_H

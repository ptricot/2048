#ifndef GRID_H
#define GRID_H

#include <QObject>

class grid : public QObject
{
    Q_OBJECT
public:
    explicit grid(QObject *parent = nullptr);
    Q_INVOKABLE void up();
    Q_INVOKABLE void down();
    Q_INVOKABLE void left();
    Q_INVOKABLE void right();
    Q_PROPERTY(QString scoreQML READ readScore NOTIFY update)
    Q_PROPERTY(QString defeatQML READ defeatTest NOTIFY update)

    Q_PROPERTY(QString c1x1QML READ read1x1 NOTIFY update)
    Q_PROPERTY(QString c1x2QML READ read1x2 NOTIFY update)
    Q_PROPERTY(QString c1x3QML READ read1x3 NOTIFY update)
    Q_PROPERTY(QString c1x4QML READ read1x4 NOTIFY update)
    Q_PROPERTY(QString c2x1QML READ read2x1 NOTIFY update)
    Q_PROPERTY(QString c2x2QML READ read2x2 NOTIFY update)
    Q_PROPERTY(QString c2x3QML READ read2x3 NOTIFY update)
    Q_PROPERTY(QString c2x4QML READ read2x4 NOTIFY update)
    Q_PROPERTY(QString c3x1QML READ read3x1 NOTIFY update)
    Q_PROPERTY(QString c3x2QML READ read3x2 NOTIFY update)
    Q_PROPERTY(QString c3x3QML READ read3x3 NOTIFY update)
    Q_PROPERTY(QString c3x4QML READ read3x4 NOTIFY update)
    Q_PROPERTY(QString c4x1QML READ read4x1 NOTIFY update)
    Q_PROPERTY(QString c4x2QML READ read4x2 NOTIFY update)
    Q_PROPERTY(QString c4x3QML READ read4x3 NOTIFY update)
    Q_PROPERTY(QString c4x4QML READ read4x4 NOTIFY update)

    Q_PROPERTY(QString o1x1QML READ color1x1 NOTIFY update)
    Q_PROPERTY(QString o1x2QML READ color1x2 NOTIFY update)
    Q_PROPERTY(QString o1x3QML READ color1x3 NOTIFY update)
    Q_PROPERTY(QString o1x4QML READ color1x4 NOTIFY update)
    Q_PROPERTY(QString o2x1QML READ color2x1 NOTIFY update)
    Q_PROPERTY(QString o2x2QML READ color2x2 NOTIFY update)
    Q_PROPERTY(QString o2x3QML READ color2x3 NOTIFY update)
    Q_PROPERTY(QString o2x4QML READ color2x4 NOTIFY update)
    Q_PROPERTY(QString o3x1QML READ color3x1 NOTIFY update)
    Q_PROPERTY(QString o3x2QML READ color3x2 NOTIFY update)
    Q_PROPERTY(QString o3x3QML READ color3x3 NOTIFY update)
    Q_PROPERTY(QString o3x4QML READ color3x4 NOTIFY update)
    Q_PROPERTY(QString o4x1QML READ color4x1 NOTIFY update)
    Q_PROPERTY(QString o4x2QML READ color4x2 NOTIFY update)
    Q_PROPERTY(QString o4x3QML READ color4x3 NOTIFY update)
    Q_PROPERTY(QString o4x4QML READ color4x4 NOTIFY update)

    QString readScore();

    QString color1x1();
    QString color1x2();
    QString color1x3();
    QString color1x4();
    QString color2x1();
    QString color2x2();
    QString color2x3();
    QString color2x4();
    QString color3x1();
    QString color3x2();
    QString color3x3();
    QString color3x4();
    QString color4x1();
    QString color4x2();
    QString color4x3();
    QString color4x4();

    QString read1x1();
    QString read1x2();
    QString read1x3();
    QString read1x4();
    QString read2x1();
    QString read2x2();
    QString read2x3();
    QString read2x4();
    QString read3x1();
    QString read3x2();
    QString read3x3();
    QString read3x4();
    QString read4x1();
    QString read4x2();
    QString read4x3();
    QString read4x4();

    Q_INVOKABLE void generer(); // génère un 2 ou 4 à un endroit au hasard
    QString readValue(int i, int j);
    bool libre();
    void coutGrid(); // pour les tests
    QString readColor(int i, int j);
    QString defeatTest();

    Q_INVOKABLE void save();
    Q_INVOKABLE void charge();

    bool estegal  (const grid &G);
    Q_INVOKABLE bool mvtinutile(int a);
    Q_INVOKABLE bool defaite();
    Q_INVOKABLE void sleep();
    Q_INVOKABLE void reset();

private:
    int score;
    int Grille[4][4];

signals:
    void update();
};

#endif // GRID_H

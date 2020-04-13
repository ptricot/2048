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

    QString readScore();

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

    void generer(); // génère un 2 ou 4 à un endroit au hasard
    int readValue(int i, int j);
    bool libre();
    void coutGrid(); // pour les tests

    Q_INVOKABLE void save();
    Q_INVOKABLE void charge();

private:
    int score;
    int Grille[4][4];

signals:
    void update();
};

#endif // GRID_H

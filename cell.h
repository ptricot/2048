#ifndef CELL_H
#define CELL_H

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
public:
    Cell(QObject *parent = nullptr);
    Cell(const Cell &C);
    QString readValue();
    Cell operator=(const Cell &C);
    Q_INVOKABLE void increment(int a);
    Q_PROPERTY(QString cptQML READ readValue NOTIFY cptChanged)
    void setValue(int value);
    int getValue();
    int value;
signals:
    void cptChanged();

};

#endif // CELL_H

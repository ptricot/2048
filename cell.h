#ifndef CELL_H
#define CELL_H

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
public:
    Cell(QObject *parent = nullptr);
    QString readValue();
    Q_INVOKABLE void increment(int a);
    Q_PROPERTY(QString cptQML READ readValue NOTIFY cptChanged)
private:
    int value;
signals:
    void cptChanged();

};

#endif // CELL_H

#ifndef CELL_H
#define CELL_H

#include <QObject>

class cell : public QObject
{
    Q_OBJECT
public:
    explicit cell(QObject *parent = nullptr);
    //Q_PROPERTY(QString valueQML READ readValue NOTIFY valueChanged)
    //QString readValue();
private:
    int value;

signals:
    //void valueChanged();

};

#endif // CELL_H

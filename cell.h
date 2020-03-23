#ifndef CELL_H
#define CELL_H

#include <QObject>

class Cell : public QObject
{
    Q_OBJECT
public:
    Cell(QObject *parent = nullptr);
    QString getValue() const;
private:
    QString value;
signals:

};

#endif // CELL_H

#include "cell.h"

Cell::Cell(QObject *parent) : QObject(parent)
{
    value = " ";
}
QString Cell::getValue() const {
    return (value);
}

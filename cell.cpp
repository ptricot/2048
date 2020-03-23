#include "cell.h"
#include"math.h"

Cell::Cell(QObject *parent) : QObject(parent)
{
    value = 0;
}

QString Cell::readValue(){
    if (value==0){return " ";}
    else{return QString::number(pow(2,value));}
}

void Cell::increment()
{
    value++;
    cptChanged();
}

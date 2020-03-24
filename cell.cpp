#include "cell.h"
#include"math.h"

Cell::Cell(QObject *parent) : QObject(parent)
{
    value = 0;
    cptChanged();
}

QString Cell::readValue(){
    if (value==0){return "0";}
    else{return QString::number(pow(2,value));}
}

void Cell::increment(int a)
{
    value+=a;
    cptChanged();
}


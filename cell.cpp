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

Cell::Cell(const Cell &C){
    this->value=C.value;
}

Cell Cell::operator=(const Cell &C){
    if(this != &C){
        value=C.value;
    }
    return *this;
}

int Cell::getValue(){
    if (value==0){return 0;}
    else{return pow(2,value);}
}
void Cell::setValue(int value){
    this->value = value;
    cptChanged();
}

void Cell::increment(int a)
{
    value+=a;
    cptChanged();
}

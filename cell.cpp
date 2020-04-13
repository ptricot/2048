#include "cell.h"

cell::cell(QObject *parent) : QObject(parent)
{
    value = 0;
}
/*
QString cell::readValue(){
    return QString::number(value);
}
*/

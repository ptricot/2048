#include "compteur.h"


Compteur::Compteur(QObject *parent) : QObject(parent)
{
    fCompteur = 10;
}
void Compteur::increment(){
    fCompteur++;
    cptChanged();
}
void Compteur::decrement(){
    fCompteur--;
    cptChanged();
}
QString Compteur::readCompteur(){
    return QString::number(fCompteur);
}

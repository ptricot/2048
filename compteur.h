#ifndef COMPTEUR_H
#define COMPTEUR_H

#include <QObject>

class Compteur : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cptQML READ readCompteur NOTIFY cptChanged)
public:
    explicit Compteur(QObject *parent = nullptr);
    Q_INVOKABLE void increment();
    Q_INVOKABLE void decrement();
    QString readCompteur();
private:
    int fCompteur;
signals:
    void cptChanged();
};

#endif // COMPTEUR_H

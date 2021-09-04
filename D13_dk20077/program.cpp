#include <iostream>
#include "program.h"
using namespace std;

SimboluSteks::SimboluSteks()
{
    steks = new char[5]; // Izveido tukšu dinamisku simbolu masīvu ar maksimāli 5 simboliem
    skaits = 0;          // ar simbolu skaitu 0.
}
SimboluSteks::~SimboluSteks()
{
    cout << "Likvidēts steks " << this;
    if (!isEmpty())                               // Ja masīvs nav tukšs,
        cout << " ar elementu skaitu " << skaits; // izdrukā elementu skaitu.
    cout << endl;
    delete[] steks;
}
void SimboluSteks::push(char el)
{
    if (!isFull())            // Ja masīvs nav pilns,
        steks[skaits++] = el; // masīvā ievieto padoto simbolu un palielina skaitu par 1.
    else
        cout << "Steks ir pilns!" << endl;
}
bool SimboluSteks::pop(char &el)
{
    if (!isEmpty()) // Ja masīvs nav tukšs,
    {
        el = steks[--skaits]; // samazina skaitu par 1 un piešķir padotajam references mainīgajam masīva pēdējā elementa vērtību,
        steks[skaits] = '\0'; // tad masīva pēdējo elementu aizvieto ar virknes beigu simbolu.
        return true;
    }
    cout << "Steks ir tukšs!" << endl;
    return false;
}
int SimboluSteks::count()
{
    return skaits; // Atgriež simbolu skaitu stekā.
}
char SimboluSteks::top()
{
    return steks[skaits - 1]; // Atgriež sibolu, kas atrodas steka augšā (pēdējais masīva elements).
}
bool SimboluSteks::isEmpty()
{
    return skaits <= 0; // Atgriež patiesu ja simbolu stekā nav.
}
bool SimboluSteks::isFull()
{
    return skaits >= 5; // Atgriež patiesu, ja simbolu skaits lielāks par maksimālo (5).
}
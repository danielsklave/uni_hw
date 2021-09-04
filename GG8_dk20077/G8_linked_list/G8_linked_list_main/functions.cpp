#include<iostream>
#include "functions.h"
using namespace std;

void print(elem *first) {
    while(first) {                  // Kamēr sarakstā ir nākamais elements
        cout << first->num << " ";  // Izvada elementa skaitļa vērtību
        first = first->next;
    }
    cout << endl;
}
void rem(elem *&first) {
    while(first) {                  // Kamēr sarakstā ir nākamais elements
        elem *p = first->next;
        delete first;               // Izdzēš elementu
        first = p;                  // Kā saraksta sākumu norāda nākamo elementu
    }
}
void append(elem *&first, elem *&last, int n) {
    elem *p = new elem(n);          // Definē norādi uz jaunu elementu ar padoto skaitli

    if(!first) first = last = p;
    else {
        last->next = p;             // Elementu pieliek klāt kā nākamo aiz pēdējā
        last = p;                   // Jauno elementu uzstāda kā pēdējo
    }
}
void reverse(elem *&first) {
    if(first == NULL) throw "tukšs"; // Izņēmumsituācijas apstrāde.
    elem *curr = first, *prev = NULL, *next = NULL;

    while (curr) {                  // Kamēr sarakstā ir nākamais elements

        next = curr->next;
        curr->next = prev;          // Nomaina nākamā elementa norādi uz iepriekšējo elementu

        prev = curr;
        curr = next;
    }
    first = prev;                   // Pēdējais elements tagad ir pirmais
}

/**************************************************************************************************************
*
* Daniels Klāve, dk20077 Programma izveidota: 22/05/2021
*
* G8. Uzrakstīt funkciju, kas apgriež sarakstu otrādi. Darbības laikā nedrīkst tikt izmantoti papildus elementi,
* kas dublētu visu esošā saraksta informāciju. Darbība jāveic, pārkabinot saites, nevis pārkopējot elementu vērtības.
*
**************************************************************************************************************/

#include<iostream>
#include "functions.h"
using namespace std;

int main() {
    int ok;
    do {
        elem *first=NULL,*last;
        string input;
        cout << "Ievadi skaitļus pa vienam, raksti 'stop', lai beigtu ievadi" << endl;
        while (true) {
            cin >> input;
            if(input != "stop") append(first,last,stoi(input));
            else break;
        }
        cout << "Saraksts pirms apgriešanas" << endl;
        print(first);
        reverse(first);
        cout << "Saraksts pēc apgriešanas" << endl;
        print(first);
        rem(first);
        cout << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

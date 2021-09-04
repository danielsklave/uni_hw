/**************************************************************************************************************
*
* Daniels Klāve, dk20077 Programma izveidota: 22/05/2021
*
* G8. Uzrakstīt funkciju, kas apgriež sarakstu otrādi. Darbības laikā nedrīkst tikt izmantoti papildus elementi,
* kas dublētu visu esošā saraksta informāciju. Darbība jāveic, pārkabinot saites, nevis pārkopējot elementu vērtības.
*
**************************************************************************************************************/

#include <list>
#include <iostream>
#include "reverse.h"
using namespace std;

void print(list<int> li) {
    for (auto itr = li.begin(); itr != li.end(); itr++)                   // Kamēr ir nākamais elements,
        cout << *itr << " ";                                              // izvadīt elementa vērtību.
    cout << endl;
}
int main()
{
    int ok;
    do {
        list<int> demoList;
        string input;
        cout << "Ievadi skaitļus pa vienam, raksti 'stop', lai beigtu ievadi" << endl;
        while (true) {
            cin >> input;
            if(input != "stop") demoList.push_back(stoi(input));
            else break;
        }
        cout << "Saraksts pirms apgriešanas" << endl;
        print(demoList);
        reverseList(demoList);
        cout << "Saraksts pēc apgriešanas" << endl;
        print(demoList);
        cout << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

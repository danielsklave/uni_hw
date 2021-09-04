/**************************************************************************************************************
*
* Daniels Klāve, dk20077 Programma izveidota: 22/05/2021
*
* GG8. Tas pats uzdevums, kas G, bet tā risinājums (a) jāpapildina ar divām lietām:
* x) vismaz viena no datu pārbaudēm jārealizē, izmantojot izņēmumsituāciju apstrādes (exception handling) mehānismu,
* y) vismaz viena funkcija (vēlams, galvenā) ir jānotestē, izmantojot vienībtestēšanu, 
* kur attiecīgā funkcija būtu jāpārbauda uz vismaz trīs dažādiem nosacījumiem; šim nolūkam, 
* kā minimums, ir nepieciešams (1) šo funkciju iznest ārā citā failā (nekā funkcija main), 
* (2) izveidot otru projektu speciāli šīs funkcijās testēšanai (tātad, kopā būs divi projekti, 
* parastais, kas izmantos funkciju, otrais, kas testēs).
*
**************************************************************************************************************/

#include<iostream>
#include "../G8_linked_list_main/functions.cpp"
using namespace std;

void test1() {
    elem *first = NULL, *last;
    int val[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) append(first,last,val[i]);
    reverse(first);
    int i = 4;
    bool correct = true;
    for(elem *el = first; el != NULL; el = el->next) {
        if (val[i--] != el->num) {
            correct = false; break;
        }
    }
    rem(first);
    cout << correct << endl;
}

void test2() {
    elem *first = NULL, *last;
    int val[2] = {93, 5};
    for(int i = 0; i < 2; i++) append(first,last,val[i]);
    reverse(first);
    int i = 1;
    bool correct = true;
    for(elem *el = first; el != NULL; el = el->next) {
        if (val[i--] != el->num) {
            correct = false; break;
        }
    }
    rem(first);
    cout << correct << endl;
}

void test3() {
    elem *first = NULL, *last;
    int val[1] = {2};
    for(int i = 0; i < 1; i++) append(first,last,val[i]);
    reverse(first);
    int i = 0;
    bool correct = true;
    for(elem *el = first; el != NULL; el = el->next) {
        if (val[i--] != el->num) {
            correct = false; break;
        }
    }
    rem(first);
    cout << correct << endl;
}

void test4() {
    elem *first = NULL;
    try {
        reverse(first);
    }
    catch(const char* z){
        if (z == "tukšs") cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    catch(...){
        cout << 0 << endl;
        return;
    }
    cout << 0 << endl;
}

int main() {
    test1(); // 1
    test2(); // 1
    test3(); // 1
    test4(); // 1
}

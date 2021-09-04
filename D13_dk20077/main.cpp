/**********************************************************************************
*
* Daniels Klāve, dk20077
*
* D13. Izveidot klasi ""Simbolu steks"", kurā glabājas masīvs ar simboliskām
* vērtībām (char) garumā 5 un steka elementu skaits. Klasei izveidot šādas metodes: 
* (1) konstruktors, 
* (2) destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī steks nav tukšs), 
* (3) metode ""Push"", kas pievieno stekam elementu, ja tas nav pilns, 
* (4) metode ""Pop"", kas izņem no steka augšējo elementu un atgriež tā vērtību, 
* (5) metode ""Count"", kas atgriež elementu skaitu stekā, 
* (6) metode ""Top"", kas atgriež augšējā elementa vērtību, 
* (7) metode ""IsEmpty"", kas noskaidro, vai steks ir tukšs, 
* (8) metode ""IsFull"", kas noskaidro, vai steks ir pilns.
* Pirms uzdevuma veikšanas precīzi noskaidrot, ko nozīmē jēdziens steks (stack) kā datu struktūra.
* 
* Izveidot programmu valodā C++, izmantojot objektorientētās programmēšanas līdzekļus
* un strukturējot programmu vismaz trīs failos. Klases hederi obligāti novietot 
* atsevišķā hedera failā (program.h). Visas metodes realizēt ārpus hedera faila – 
* speciālā C++ failā (program.cpp). Funkcija main ievietojama vēl citā C++ failā (main.cpp).
* Klases dati pēc noklusēšanas ir slēpti (private), bet metodes atklātas (public).
* Šīs programmas ietvaros NAV obligāti jānodrošina tāda lietotāja saskarne,
* kāda tika prasīta iepriekšējos trīs uzdevumos (main funkciju drīkst “cieti” iekodēt). 
* Citas prasības sk. Laboratorijas darbu noteikumos.
* 
* Programma izveidota: 10/12/2020
*
**********************************************************************************/

#include <iostream>
#include "program.h"
using namespace std;

int main()
{
    SimboluSteks s; // Konstruktors izveido statisku objektu SiboluSteks ar nosaukumu s.
    s.push('a');    // Metode ieliek stekā simbolu 'a'.
    s.push('b');
    cout << s.top() << endl; // Izdrukā simbolu, kas atrodas steka augšā.
    s.push('c');
    cout << s.count() << endl; // Izdrukā šī brīža simbolu skaitu stekā.
    s.push('d');
    s.push('e');
    s.push('f'); // Metode izdrukās paziņojumu ka steks ir pilns, jo
    s.push('g'); // steks jau ir sasniedzis maksimālos 5 simbolus.
    char el;
    if (s.pop(el))
        cout << el << endl; // Metode izņem ārā no steka augšējo simbolu
    if (s.pop(el))
        cout << el << endl; // un izdrukā šo simbolu, jo steks vēl nav tukšs.
    if (s.pop(el))
        cout << el << endl;
    if (s.pop(el))
        cout << el << endl;
    if (s.pop(el))
        cout << el << endl;
    if (s.pop(el))
        cout << el << endl; // Metode izdrukās paziņojumu, ka steks ir tukšs,
    if (s.pop(el))
        cout << el << endl; // jo steka simbolu skaits ir 0.
    return 0;               // Destruktors izdrukās paziņojumu, ka steks ir likvidēts, taču bez elementu skaita paziņojuma, jo steks ir tukšs.
}

/**********************************************************************************
 *      Programmas velāma reakcija          Rezultāts 
 *
 *      b                                       +
 *      3                                       +
 *      Steks ir pilns!                         +            
 *      Steks ir pilns!                         +            
 *      e                                       +
 *      d                                       +
 *      c                                       +
 *      b                                       +
 *      a                                       +
 *      Steks ir tukšs!                         +
 *      Steks ir tukšs!                         +
 *      Likvidēts steks 0x61fe00                +                            
 *********************************************************************************/
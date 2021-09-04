/*******************************************************************
*
* Daniels Klāve, dk20077
*
* F8. Doti divi faili f1 un f2. Failā f1 ir patvaļīgs teksts, 
* failā f2 ir ne vairāk kā 40 vārdu pārīšu, kas atdalīti ar komatiem. 
* Izdrukāt failā tekstu no ieejas faila f1, kurā visi vārdi, 
* kas ir sastopami failā f2 kā pirmā komponente no pārīša, 
* tiek aizstāti ar tam atbilstošo failā f2 norādīto vārdu. 
* Drīkst uzskatīt, ka vārda garums failā nepārsniedz 40 simbolus. 
* Par vārdu uzskatīt patvaļīgu simbolu virkni, 
* kas atdalīta ar tukšumiem vai pieturas zīmēm 
* (punkts, komats, apaļās iekavas, izsaukuma zīme, jautājuma zīme).
*
* Programma izveidota: 04/03/2021
*******************************************************************/

#include <fstream>
#include <iostream>
using namespace std; 

int main()
{
    int ok;
    do {
        fstream f1("f1.txt", ios::in), f2("f2.txt", ios::in), fout("out.txt", ios::out);
        
        if(!f1.is_open()) {cout << "File f1.txt doesn't exist" << endl;} // Pārbauda vai fails eksistē
        else if(!f2.is_open()) {cout << "File f2.txt doesn't exist" << endl;} 
        else{
            string inl;
            getline(f1, inl);
            while(f1) { // Katrai faila f1 rindai
                string outLine, word;
                
                for(int i = 0; i < inl.size(); i++) { // katram riniņas simbolam
                    // Pārbauda, vai simbols ir pieturzīme
                    bool delim = inl[i] == ' ' || inl[i] == '.' || inl[i] == ',' || inl[i] == '(' || inl[i] == ')' || inl[i] == '!' || inl[i] == '?';

                    if(!delim) word += inl[i]; // ja nav pieturzīme, simbolu pievieno vārda virknei.

                    if(delim || i == inl.size() - 1) { // Ja ir pieturzīme vai ir rindiņas pēdējais simbols,
                        string inl2;
                        getline(f2, inl2);
                        while(f2) { // Katrai faila f2 rindai
                            if(inl2.substr(0, inl2.find(',')) == word){ // Ja vārds sakrīt ar pāra pirmo komponenti,
                                word = inl2.substr(inl2.find(',') + 1); // kā vārda vērtību piešķir pāra otro komponenti
                                break;
                            }
                            getline(f2, inl2);
                        }
                        f2.clear(); f2.seekg(0, ios::beg);
                        outLine += word; // izvades virknei pievieno vārda virkni.
                        word = "";
                    }
                    if(delim) outLine += inl[i]; // Ja ir pieturzīme, to pievieno izvades virknei.
                }
                fout << outLine << endl; // Ieraksta izvades virkni failā out.txt.
                getline(f1, inl);
            };
        }
        f1.close(); f2.close(); fout.close();
        cout << "Vai turpināt (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}
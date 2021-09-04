#include <list>
#include "reverse.h"
using namespace std;
void reverseList(list<int> &li) {
    if(li.empty()) throw "tukšs"; // Izņēmumsituācijas apstrāde.
    for (auto itr = prev(prev(li.end())); itr != prev(li.begin()); itr--) // Iet cauri katram saraksta elementam atpakaļgaitā, sākot at priekšpēdējo.
        li.splice(li.end(), li, itr++);                                   // Parvieto elementu uz saraksta beigām.
}

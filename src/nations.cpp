#include "../include/nations.h"
#include <iostream>
using namespace std;


Nations::Nations() {
    nations = new List(Sorted);
}

void Nations::addNation(Nation* nation) {
    nations->add(nation);
}

Nation* Nations::getNation(string s) {
    Nation* nation = (Nation*)nations->remove(s.c_str());
    // Make sure nation exists
    if (nation == nullptr) {
        cout << "\t\tCouldn't find nation with " << s << " abbreviation." << endl;
        return nullptr;
    }
    // Done with object, adding back to list
    nations->add(nation);
    return nation;
}

Nation* Nations::removeNation(string s) {
    return (Nation*)nations->remove(s.c_str());
}

void Nations::display() {
    nations->displayList();
}

void Nations::display(string s) {
    Nation* nation = (Nation*)nations->remove(s.c_str());
    // Only try to display nation if its not a nullpointer
    if (nation == nullptr) {
        cout << "\t\tCouldn't find nation with " << s << " abbreviation." << endl;
        return;
    }
    // Nation is good -> display it
    nations->displayElement(s.c_str());
    // Done with object, adding back to list
    nations->add(nation);
}
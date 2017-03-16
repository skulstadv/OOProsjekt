#include "../include/nations.h"
#include <iostream>
using namespace std;


Nations::Nations() {
    nations = new List(Sorted);
}

bool Nations::addNation(Nation* nation) {
    // Dont want to add nullptr
    if (nation == nullptr) {
        // Debug
        cout << "Tried adding Nation* nullptr.. you dont wanna do that.\n";
        return false;
    }
    // Return false if the nation abbreviation is in use
    if (nations->inList(nation->getName().c_str()))
        return false;
    // Everything seems to be ok
    nations->add(nation);
    return true;   
}

Nation* Nations::getNation(string s) {
    Nation* nation = (Nation*)nations->remove(s.c_str());
    // Make sure nation exists
    if (nation == nullptr) {
        // Debug
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
    nation->display();
    // Done with object, adding back to list
    nations->add(nation);
}
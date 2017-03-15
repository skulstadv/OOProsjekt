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
    if (nation == nullptr) {
        cout << "\t\tCouldn't find nation with " << s << " abbreviation." << endl;
        return nullptr;
    }
    nations->add(nation);
    return nation;
}

Nation* Nations::removeNation(string s) {
    //TODO
    return new Nation("temp");
}

void Nations::display() {
    //TODO
}

void Nations::display(string s) {
    //TODO
}
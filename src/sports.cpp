#include "../include/sports.h"
#include <iostream>
#include <fstream>
using namespace std;


Sports::Sports() {
    sports = new List(Sorted);
}

bool Sports::addSport(Sport* sport) {
    if (sports->inList(sport->getName().c_str()))
        return false;
    // Sport has unique name, adding to list
    sports->add(sport);
    return true;
}

Sport* Sports::getSport(string s) {
    Sport* sport = (Sport*)sports->remove(s.c_str());
    // Only add the sport if it actually exists
    if (sport != nullptr)
        sports->add(sport);
    return sport;
}

Sport* Sports::removeSport(string s) {
    Sport* sport = (Sport*)sports->remove(s.c_str());
    return sport;
}

void Sports::display() {
    sports->displayList();
}

int Sports::getNumber() {
    return sports->noOfElements();
}

List * Sports::getList() {
    return sports;
}

void Sports::writeToFile(ofstream& out) {
    int num = sports->noOfElements();
    out << num << endl;
    Sport* sport;
    for (int i = 1; i <= num; i++) {
        sport = (Sport*)sports->removeNo(i);
        sport->writeToFile(out);
        sports->add(sport);
    }
}

void Sports::readFromFile(std::ifstream & in) {
    int num = 0; 
    // Reads number of sports from file
    in >> num;
    // Ignore the newline
    in.ignore();
    string* sport_name = new string();
    // Empty old list first
    while (sports->noOfElements() > 0)
        delete (Sport*)sports->removeNo(1);
    // Add new sports to list
    for (int i = 0; i < num; i++) {
        // Read sport name first
        getline(in, *sport_name);
        sports->add(new Sport(*sport_name, in));
        // If there are more than one sport we need to ignore the two newlines
        in.ignore();
    }
}
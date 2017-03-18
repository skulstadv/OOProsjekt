#include "../include/sports.h"
#include <iostream>
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

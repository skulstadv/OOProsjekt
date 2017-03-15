#include "../include/nation.h"
#include "../include/utility.h"
#include <iostream>
using namespace std;

Nation::Nation(string s) : TextElement(s.c_str()) {
    nation_long = new string();
    getString(*nation_long, "\t\tNation name: ");
    contact_name = new string();
    getString(*contact_name, "\t\tContact name: ");
    contact_tel = getNumber(0, 1, 2);
    num_participants = 0;
}

bool Nation::addParticipantID(Participant* participant) {
    //TODO
    return false;
}

Participant* Nation::getParticipant(int n) {
    //TODO
    return new Participant(0);
}

Participant* Nation::removeParticipant(int n) {
    //TODO
    return new Participant(0);
}

string Nation::getName() {
    //TODO
    return string();
}

void Nation::display() {
    cout << "\t\tNation abbreviation: " << text << "\n\t\tNation name: ";
    cout << *nation_long << "\n\t\tContact name: " << *contact_name;
    cout << "\n\t\tContact tel: " << contact_tel;
    cout << "\n\t\tNumber participants: " << num_participants << endl;
}

void Nation::displayParticipants() {
    //TODO
}

void Nation::displayParticipant(int n) {
    //TODO
}
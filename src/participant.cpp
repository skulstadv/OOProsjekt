#include "../include/participant.h"
#include "../include/utility.h"
#include "../include/main.h"
#include <iostream>
using namespace std;



Participant::Participant(int n, std::ifstream& in) : NumElement(n) {
    name = new string();
    nation_short = new string();
    getline(in, *name);
    getline(in, *nation_short);
    // Add the participant to the right nation
    nations->getNation(*nation_short)->addParticipantID(number);
    in >> isFemale;
}

Participant::Participant(int n) : NumElement(n) {
    name = new string();
    // Get name of participant from user
    getLine(*name, "Enter name of participant: ", 2);
    // Get nation affiliation of participant from user
    nation_short = getNationAbbreviation(2);
    // Get gender from user
    isFemale = (getInt(0, 1, 2, "Is the participant a female? ") == 1);
}

Participant::~Participant() {
    delete name;
    delete nation_short;
}

void Participant::display() {
    cout << "\t\tParticipant id: " << getNumber() << "\n\t\tParticipant name: ";
    cout << *name << "\n\t\tNation short: " << *nation_short;
    cout << "\n\t\tGender: ";
    if (isFemale)
        cout << "Male\n\n";
    else
        cout << "Female\n\n";
}


int Participant::getNumber() {
    return number;
}

string* Participant::getNationName() {
    return nation_short;
}

std::string* Participant::getName() {
    return name;
}

void Participant::writeToFile(ofstream& out) {
    // Write id first
    out << number << endl;
    out << *name << endl;
    out << *nation_short << endl;
    // Two endlines between participants for readability
    out << isFemale << endl << endl;
}

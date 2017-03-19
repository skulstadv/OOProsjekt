#include "../include/participants.h"
#include <iostream>
#include <fstream>
using namespace std;


Participants::Participants() {
    participants = new List(Sorted);
}

Participants::~Participants() {
    //TODO
}

bool Participants::addParticipant(Participant* participant) {
    // Dont want to add nullptr
    if (participant == nullptr) {
        // Debug
        cout << "Tried adding Participant* nullptr.. you dont wanna do that.\n";
        return false;
    }
    // Return false if the ID is in use
    if (participants->inList(participant->getNumber()))
        return false;
    // All good, adding to participants
    participants->add(participant);
    return true;
}

Participant* Participants::getParticipant(int n) {
    Participant* ret = (Participant*)participants->remove(n);
    if (ret == nullptr) {
        return nullptr;
    }
    // Put it back in list before returning pointer 
    //addParticipant(ret);
    participants->add(ret);
    return ret;
}

Participant* Participants::removeParticipant(int n) {
    Participant* ret = (Participant*)participants->remove(n);
    return ret;
}

void Participants::displayParticipant(string s) {
    Participant* participant;
    int num = participants->noOfElements();
    // Loops through all participants
    for (int i = 1; i <= num; i++) {
        participant = (Participant*)participants->removeNo(i);
        // If the name of the participant contains string s we got a match
        if (participant->getName()->find(s) != string::npos)
            participant->display();
        // Put participant back where we found it (participants is sorted)
        participants->add(participant);
    }
}

void Participants::display() {
    participants->displayList();
}

int Participants::getNumParticipants() {
    return participants->noOfElements();
}

int Participants::getNumber() {
    return participants->noOfElements();
}

List * Participants::getList() {
    return participants;
}

void Participants::writeToFile(ofstream& out) {
    int num = participants->noOfElements();
    out << num << endl;
    Participant* participant;
    for (int i = 1; i <= num; i++) {
        participant = (Participant*)participants->removeNo(i);
        participant->writeToFile(out);
        participants->add(participant);
    }
}

void Participants::readFromFile(std::ifstream & in) {
    int num = 0;
    // Reads number of participants in file
    in >> num;
    // Ignores the newline
    in.ignore();
    int participant_id;
    // Empty old list first
    while (participants->noOfElements() > 0)
        delete participants->removeNo(1);
    // Add new ones
    for (int i = 0; i < num; i++) {
        // Read participant id first
        in >> participant_id;
        // Ignore newline and make ready for participant class to read
        in.ignore();
        participants->add(new Participant(participant_id, in));
        // If there are more participants we need to ignore the two newlines
        in.ignore(2);
    }
}


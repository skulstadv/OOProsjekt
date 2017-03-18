#include "../include/participants.h"
#include <iostream>
using namespace std;


Participants::Participants() {
    participants = new List(Sorted);
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
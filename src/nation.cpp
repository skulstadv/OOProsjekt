#include "../include/nation.h"
#include "../include/utility.h"
#include "../include/main.h"
#include <iostream>
using namespace std;

Nation::Nation(string s) : TextElement(s.c_str()) {
    participants_id = new List(Sorted);
    nation_long = new string();
    // Get name from user
    getLine(*nation_long, "Nation name: ", 2);
    contact_name = new string();
    // Get contact name from user
    getLine(*contact_name, "Contact name: ", 2);
    // Get telephone number from user
    contact_tel = getInt(0, 1, 2);
    num_participants = 0;
}

bool Nation::addParticipantID(int n) {
    if (participants_id->inList(n))
        return false;
    participants_id->add(new NumElement(n));
    num_participants++;
    return true;
}

Participant* Nation::getParticipant(int n) {
    // ** Probably wont work **
    Participant* participant;
    NumElement* num_element = (NumElement*)participants_id->remove(n);
    participant = participants->getParticipant(num_element->getNumber());
    return participant;
}

Participant* Nation::removeParticipant(int n) {
    // ** Shoulndt return anything **
    participants_id->remove(n);
    return NULL;
     
}

string Nation::getName() {
    return text;
}

void Nation::display() {
    cout << "\t\tNation abbreviation: " << text << "\n\t\tNation name: ";
    cout << *nation_long << "\n\t\tContact name: " << *contact_name;
    cout << "\n\t\tContact tel: " << contact_tel;
    cout << "\n\t\tNumber participants: " << num_participants << endl << endl;
}

void Nation::displayParticipants() {
    /*
     *  Needs to be moved to main to work
     */
    // Loop through participants list and display corresponding participant
    int sum = participants_id->noOfElements();
    // Stores the object containig the ID of the participant (an int*)
    NumElement* participant_id;
    // listTool2B index origin is 1 (!)
    for (int i = 1; i <= sum; i++) {
        // Get participant id <i> from participants_id list
        participant_id = (NumElement*)participants_id->removeNo(i);
        participants_id->add(participant_id);
        // Display the participant with this ID
        participants->getParticipant(participant_id->getNumber())->display();
    }
}

void Nation::displayParticipant(int n) {
    //TODO
}
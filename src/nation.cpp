#include "../include/nation.h"
#include "../include/utility.h"
#include "../include/participants.h"
#include "../include/main.h"
#include <iostream>
#include <fstream>

using namespace std;

Nation::Nation(std::string s, std::ifstream& in) : TextElement(s.c_str()) {
    participants_id = new List(Sorted);
    // Number of ids in participants list
    int num;
    // The most recent id in participant list to add
    int id;
    in >> num;
    for (int i = 0; i < num; i++) {
        in >> id;
        // Adding id to list
        // TODO - Add check for existance in participants list
        participants_id->add(new NumElement(id));
    }
    in.ignore();
    in.ignore();
    nation_long = new string();
    getline(in, *nation_long);
    contact_name = new string();
    getline(in, *contact_name);
    in >> contact_tel;
    in >> num_participants;
}

Nation::Nation(string s) : TextElement(s.c_str()) {
    participants_id = new List(Sorted);
    nation_long = new string();
    // Get name from user
    getLine(*nation_long, "Nation name: ", 2);
    contact_name = new string();
    // Get contact name from user
    getLine(*contact_name, "Contact name: ", 2);
    // Get telephone number from user
    contact_tel = getInt(11111111, 99999999,2,"Enter the Phone number of the contact: ");
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
    num_participants--;
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
        //
        int temp_id = participant_id->getNumber();
        // Display the participant with this ID
        Participant* part;
        part = participants->getParticipant(temp_id);
        part->display();
    }
}

void Nation::displayParticipant(int n) {
    //TODO
}

void Nation::writeToFile(ofstream& out) {
    // Write unique abbreviation first
    out << text << endl;
    out << participants_id->noOfElements() << ' ';
    NumElement* ne;
    // Write all num elements in participants id list to file
    for (int i = 1; i <= participants_id->noOfElements(); i++) {
        ne = (NumElement*)participants_id->removeNo(i);
        // Write id to file
        out << ne->getNumber() << ' ';
        participants_id->add(ne);
    }
    out << endl;
    out << *nation_long << endl;
    out << *contact_name << endl;
    out << contact_tel << ' ' << num_participants << endl;
}

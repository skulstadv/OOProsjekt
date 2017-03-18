#include "../include/result.h"
#include <iostream>
using namespace std;


Result::Result(int result, int id) : NumElement(result) {
    participant_id = id;
}

int Result::getParticipantID() {
    return participant_id;
}

void Result::display() {
    cout << "\t\tParticipant ID: " << participant_id;
    cout << "\tResult: " << getNumber() << endl;
}

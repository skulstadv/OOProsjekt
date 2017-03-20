#include "../include/result.h"
#include <iostream>
using namespace std;


Result::Result(int result, int id, string s) : NumElement(result) {
    participant_id = id;
    result_data = new string();
    *result_data = s;
}

Result::~Result() {
}

int Result::getParticipantID() {
    return participant_id;
}

std::string Result::getData() {
    return *result_data;
}

void Result::display() {
    cout << "\t\tParticipant ID: " << participant_id;
    cout << "\tResult: " << getNumber() << endl;
}

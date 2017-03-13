#pragma once
#ifndef OOProject_PARTICIPANT_H_
#define OOProject_PARTICIPANT_H_
#include <string>
#include "ListTool2B.h"
using namespace std;


// A participant in the olympics
class Participant : public NumElement {

protected:
    string name;
    string nation_short;
    bool gender;


public:
    // Creates a participant with unique name @s
    Participant(string s);

    // Display this participants data
    void display();

};



#endif
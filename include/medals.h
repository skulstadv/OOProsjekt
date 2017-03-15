#pragma once
#ifndef OOProject_MEDALS_H_
#define OOProject_MEDALS_H_
#include <string>
#include "ListTool2B.h"
#include "medal.h"
using namespace std;


// Containter class for medals
class Medals { 

private:
    // All the medals won by text (nation abbreviation) in the olympic games
    List* medals;


public:
    // Add medal to linked list
    void addMedal(Medal);

    // Get medal by its unique string @s
    Medal getMedal(string s);

    // Removes medal for nation with name @s
    Medal removeMedal(string s);
};

#endif





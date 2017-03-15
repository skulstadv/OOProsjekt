#ifndef OOProject_MEDALS_H_
#define OOProject_MEDALS_H_
#include "listTool2b.h"
#include "medal.h"

// Containter class for medals
class Medals {

    // All the medals won by text (nation abbreviation) in the olympic games
    List* medals;

public:
    // Constructor
    Medals();

    // Add medal to linked list
    void addMedal(Medal*);

    // Get medal by its unique string -s
    Medal* getMedal(std::string s);

    // Removes medal for nation with name -s
    Medal* removeMedal(std::string s);
};

#endif





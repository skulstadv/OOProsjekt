#ifndef OOProject_SPORTS_H_
#define OOProject_SPORTS_H_
#include "listTool2B.h"
#include "sport.h"

// Container class for all sports
class Sports { 

    // All the sports in the olympic games
    List* sports;

public:
    // Constructor
    Sports();

    // Add sport to linked list
    void addSport(Sport* sport);

    // Get sport by its unique string -s
    Sport* getSport(std::string s);

    // Removes sport with ID -s
    Sport* removeSport(std::string s);

};

#endif

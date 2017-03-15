#ifndef OOProject_NATIONS_H_
#define OOProject_NATIONS_H_
#include "nation.h"
#include "listTool2B.h"
#include <string>

// Container class for all nations
class Nations { 

    // All the nations in the olympic games
    List* nations;

public:
    // Constructor
    Nations();

    // Add nation to linked list
    void addNation(Nation* nation);

    // Get nation by its unique string -s
    // -return nullptr if no match
    Nation* getNation(std::string s);

    // Removes nation with ID -s
    Nation* removeNation(std::string s);

    // Displays all nations
    void display();

    // Displays all nations with ID -s
    void display(std::string s);

};

#endif


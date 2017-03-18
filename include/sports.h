#ifndef OOProject_SPORTS_H_
#define OOProject_SPORTS_H_
#include "listTool2B.h"
#include "sport.h"
#include <fstream>

// Container class for all sports
class Sports { 

    // All the sports in the olympic games
    List* sports;

public:
    // Constructor
    Sports();

    // Add sport to linked list
    // -return true if successfully added
    bool addSport(Sport* sport);

    // Get sport by its unique string -s
    Sport* getSport(std::string s);

    // Removes sport with ID -s
    Sport* removeSport(std::string s);

    // Display all sports
    void display();

    // Returns number of sports in the list
    int getNumber();

    // Returns list
    List* getList();

    // Write class to file
    void writeToFile(std::ofstream& out);

    // Read class from file
    void readFromFile(std::ifstream& in);
};

#endif

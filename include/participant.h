#ifndef OOProject_PARTICIPANT_H_
#define OOProject_PARTICIPANT_H_
#include "listTool2B.h"
#include <string>
#include <fstream>

// A participant in the olympics
class Participant : public NumElement {

    // Name of participant
    std::string* name;
    // Nation abbreviation
    std::string* nation_short;
    // Gender of participant 0 = man, 1 = woman
    bool isFemale;

public:
    // Read from file constructor
    Participant(int n, std::ifstream& in);

    // Constructor, -n is a unique number for this participant
    Participant(int n);

    // Destructor
    ~Participant();

    // Display this participants data
    void display();

    // Returns number for this participant
    int getNumber();

    // Get this participants nation abbreviation
    std::string* getNationName();

    // Get this participants name
    std::string* getName();

    // Write class to file
    void writeToFile(std::ofstream& out);
};
#endif
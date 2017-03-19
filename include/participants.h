#ifndef OOProject_PARTICIPANTS_H_
#define OOProject_PARTICIPANTS_H_
#include "listTool2B.h"
#include "participant.h"
#include <string>
#include <fstream>

// Container class for all participants
class Participants {

    // All the participants in our program
    List* participants;

public:
    // Constructor
    Participants();

    // Destructor
    ~Participants();

    // Add participant to linked list
    // -return true if successfull (id unique)
    bool addParticipant(Participant* participant);

    // Get participant by its ID -n
    Participant* getParticipant(int n);

    // Removes participant with ID -n
    Participant* removeParticipant(int n);

    // Display participant with name containing or matching -s
    void displayParticipant(std::string s);

    // Displays all participants
    void display();

    // Return the number of participants
    int getNumParticipants();

    // Returns how many participants in the list
    int getNumber();

    // Returns list
    List* getList();

    // Write class to file
    void writeToFile(std::ofstream& out);

    // Read class from file
    void readFromFile(std::ifstream& in);
};

#endif
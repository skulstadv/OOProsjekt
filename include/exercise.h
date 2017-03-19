#ifndef OOProject_EXERCISE_H_
#define OOProject_EXERCISE_H_
#include <string>
#include "listTool2B.h"
#include "participant.h"


// A specific exercise in a sport
class Exercise : public NumElement {

    // Linked sorted list containing ID of participants for 
    // global participants list
    List* participants_id;

    // Linked sorted list containing all results
    // Sorted after results (ascending). Gold winner will be last
    // person in list. Get participant with result->getParticipantID
    List* results;

    // Name of exercise
    std::string* name;

    // Time of day the exercise will take place
    int time_of_day;

    // Date of the exercise
    unsigned int date;

public:

    // Constructor - Read from file
    Exercise(int n, std::ifstream& in);

    // Constructor
    // Creates a new Exercise object with unique ID -n
    Exercise(int n);

    // Display this object
    void display();

    // Display all participants a part of this exercise
    void displayParticipants();

    // Insert participant with ID -n in participants list
    // -return true if successfull
    // -return false if participant ID already in list
    bool addParticipantID(int n);

    // Remove participant with ID -n from this exercise 
    // -return true if participant was removed
    bool removeParticipantID(int n);

    // Returns the list with results
    List* getResultsList();

    // Returns the list of participants
    List* getParticipantsIDList();

    // Self explanatory
    void setName();

    // Self explanatory
    void setDate();

    // Self explanatory
    void setTime();

    // Returns name of exercise
    std::string* getName();

    // Writes exercise to file
    void writeToFile(std::ofstream& out);

    // Read exercise results from file
    bool readResultsFromFile();

    // Write exercise results to file
    bool writeResultsToFile();

    // Read participants from file
    void readParticipantsFromFile();

    // Write participants to file
    void writeParticipantsToFile();
};
#endif

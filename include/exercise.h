#ifndef OOProject_EXERCISE_H_
#define OOProject_EXERCISE_H_
#include <string>
#include "listTool2B.h"
#include "participant.h"


// A specific exercise in a sport
class Exercise : public NumElement {

    // Linked sorted list containing ID of participants for 
    // global participants list
    List* participants;

    // Name of exercise
    std::string* name;

    // Time of day the exercise will take place
    int time_of_day;

    // Date of the exercise
    int date;

public:
    Exercise();

    // Constructor
    // Creates a new Exercise object with unique ID -n
    Exercise(int n);

    // Display this object
    void display();

    // Display all participants a part of this exercise
    void displayParticipants();

    // Insert participant with ID -n in participants list
    // -return true if successfull
    bool addParticipantID(int n);

    // Get participant with ID -n from global participants list
    // -return the participant object removed from global participants list
    Participant* getParticipant(int n);

    // Remove participant with ID -n from this exercise 
    // -return true if participant was removed
    bool removeParticipantID(int n);
};
#endif

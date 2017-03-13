#pragma once
#ifndef OOProject_PARTICIPANTS_H_
#define OOProject_PARTICIPANTS_H_
#include <string>
#include "ListTool2B.h"
#include "participant.h"
using namespace std;


// Container class for all participants
class Participants {

private:
    // All the participants in our program
    List* participants;


public:
    // Add participant to linked list
    void addParticipant(Participant);

    // Get participant by its ID @n
    Participant getParticipant(int n);

    // Removes participant with ID @n
    Participant removeParticipant(int n);

    // Display participant with name containing or matching @s
    void displayParticipant(string s);

};

#endif
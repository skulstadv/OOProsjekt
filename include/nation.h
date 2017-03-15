#ifndef OOProject_NATION_H_
#define OOProject_NATION_H_
#include <string>
#include "listTool2B.h"
#include "participant.h"

// A nation - Contains list of participants and contact info for one person
class Nation : public TextElement {

    // A list of IDs of participants belonging to this nation
    // This is just a linked list of integers (NumElements)
    List* participants;

    // Full name of this nation
    std::string* nation_long;

    // Contact telephone number for this nation
    std::string* contact_name;

    // Contact name for this nation
    int contact_tel;

    // Number of participants from this nation
    // Should be equal to participants->noOfElements()
    int num_participants;

public:
    Nation();

    // Constructor
    // -s unique 3 char abbreviation of nation name
    Nation(std::string s);

    // Inserts participant ID into list of participant IDs
    // -return true if ID successfully added to list
    bool addParticipantID(Participant* participant);

    // Retrieves the participant object with ID -n from 
    // global participants array
    Participant* getParticipant(int n);

    // Remove participant with ID -n from participants list
    Participant* removeParticipant(int n);

    // -return the nation_long name of this nation
    std::string getName();

    // Display this nations data excluding participants
    void display();

    // Display this nations participants
    void displayParticipants();

    // Display the participant with ID -n
    void displayParticipant(int n);
};
#endif
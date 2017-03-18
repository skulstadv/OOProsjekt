#ifndef OOProject_RESULT_H_
#define OOProject_RESULT_H_
#include "listTool2B.h"


class Result : public NumElement {

// Participant this result describes. Contains id in global participants var
int participant_id;

public: 
    Result();

    // Constructor
    Result(int result, int id);

    // returns the value of this result (aka 16pts for gold, 15 for bronze)
    int getParticipantID();

    // Displays this result
    void display();
};



#endif

#ifndef OOProject_RESULT_H_
#define OOProject_RESULT_H_
#include "listTool2B.h"
#include <string>


class Result : public NumElement {

// Participant this result describes. Contains id in global participants var
int participant_id;

// Result in whatever form the sport requires. Stored as a string for convenience
std::string* result_data;

public: 
    Result();

    // Constructor
    Result(int result, int id, std::string s);

    // Deconstructor
    ~Result();

    // returns the value of this result (aka 16pts for gold, 15 for bronze)
    int getParticipantID();

    // Returns the data of this result
    std::string getData();

    // Displays this result
    void display();
};



#endif

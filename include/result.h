#ifndef OOProject_RESULT_H_
#define OOProject_RESULT_H_

class Result : public NumElement() {

    // Participant id 
    int participant_id;

public: 
    // Constructor
    Result(int n) : NumElement(n);

    // returns num element
    int getParticipantID();
}



#endif

#include "../include/result.h"
using namespace std;


Result::Result(int n) : NumElement(n){
    participant_id = n;
}

int Result::getParticipantID() {
    return participant_id;
}

#ifndef OOProject_MAIN_H_
#define OOProject_MAIN_H_
#include "../include/participants.h"
#include "../include/sports.h"
#include "../include/nations.h"
#include "../include/medals.h"
#include "../include/points.h"


// Global variables
extern Participants* participants;
extern Sports* sports;
extern Nations* nations;
extern Medals* medals;
extern Points* points;


// Prints helpmessage for main switch
void help();

// Switch for editing/creating nations
void nationSwitch();

// Switch for editing/creating sports
void participantSwitch();

// Switch for editing/creating participants
void sportSwitch();

// Switch for editing/creating exercises
void exerciseSwitch();

#endif
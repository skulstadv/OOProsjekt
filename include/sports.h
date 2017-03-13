#pragma once
#ifndef OOProject_SPORTS_H_
#define OOProject_SPORTS_H_
#include <string>
#include "ListTool2B.h"
#include "sport.h"
using namespace std;


// Container class for all sports
class Sports { 

private:
    // All the sports in the olympic games
    List* sports;


public:
    // Add sport to linked list
    void addSport(Sport);

    // Get sport by its unique string @s
    Sport getSport(string s);

    // Removes sport with ID @s
    Sport removeSport(string s);

};

#endif

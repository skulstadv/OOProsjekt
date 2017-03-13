#pragma once
#ifndef OOProject_NATIONS_H_
#define OOProject_NATIONS_H_
#include <string>
#include "ListTool2B.h"
#include "nation.h"
using namespace std;


// Container class for all nations
class Nations { 

private:
    // All the nations in the olympic games
    List* nations;


public:
    // Add nation to linked list
    void addNation(Nation);

    // Get nation by its unique string @s
    Nation getNation(string s);

    // Removes nation with ID @s
    Nation removeNation(string s);

    // Displays all nations
    void display();

    // Displays all nations with ID @s
    void display(string s);

};

#endif


#ifndef OOProject_POINTS_H_
#define OOProject_POINTS_H_
#include "listTool2B.h"
#include "Point.h"
#include <string>


// Containter class for points
class Points { 

    // All the points won by text (nation abbreviation) in the olympic games
    List* points;

public:
    // Constructor
    Points();

    // Add point to linked list
    void addPoint(Point*);

    // Get point by its unique string -s
    Point* getpoint(std::string s); 

    // Removes point for nation with name -s
    Point* removepoint(std::string s);
};

#endif






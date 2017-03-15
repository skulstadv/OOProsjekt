#include "../include/point.h"
using namespace std;


Point::Point(string s) : TextElement(s.c_str()) {
    //TODO
}

int Point::getPoints() {
    return num_points;
}
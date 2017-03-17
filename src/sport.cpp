#include "../include/sport.h"
#include "../include/utility.h"
#include <iostream>
using namespace std;


Sport::Sport(string s) : TextElement(s.c_str()) {
    exercises = new List(Sorted);
    if (getInt(0, 1, 2, "Write score type, Score = 0, Time = 1") == 0)
        score_type = SportScore(SCORE);
    else
        score_type = SportScore(TIME);
}

void Sport::addExercise(Exercise* exercise) {
    // If unique id taken do nothing and just return
    if (exercises->inList(exercise->getNumber()))
        return;
    // id is unique, adding to list
    exercises->add(exercise);

}

Exercise* Sport::getExercise(int n) {
    Exercise* exercise = (Exercise*)exercises->remove(n);
    // Add it back to list before returning it
    addExercise(exercise);
    return exercise;
}

Exercise* Sport::removeExercise(int n) {
    return (Exercise*)exercises->remove(n);
}

void Sport::display() {
    cout << "\t\tName of sport: " << text;
    cout << "\n\t\tScore type: ";
    if (score_type == 0)
        cout << "Score\n";
    else
        cout << "Time\n";
    exercises->displayList();
    cout << endl;
}

string Sport::getName() {
    return text;
}

    void Sport::setSportName(string s) {
        strcpy_s(text, s.size()+1, s.c_str());
}

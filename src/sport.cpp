#include "../include/sport.h"
#include "../include/utility.h"
#include <iostream>
using namespace std;


Sport::Sport(std::string s, std::ifstream & in) : TextElement(s.c_str()) {
    // String for dumping our ---exerciseBegin-- line
    string dump;
    exercises = new List(Sorted);
    int int_score_type;
    int num_exercises;
    int exercise_id;
    in >> int_score_type;
    // Add score_type
    if (int_score_type)
        score_type = SportScore(1);
    else
        score_type = SportScore(0);
    // Ignore newline
    in.ignore();
    // Read amount of exercises in exercises list from file
    in >> num_exercises;
    for (int i = 0; i < num_exercises; i++) {
        // ID of this exercise
        in >> exercise_id;
        // Read exercise from file
        // Ignore --------Exercise-------- line
        in.ignore();
        getline(in, dump);
        exercises->add(new Exercise(exercise_id, in));
        // Ignore --------Exercise-------- end line
        in.ignore();
        getline(in, dump);
    }
    // Ignore newline if 0 exercises beacause getline does this if there are
    if (!num_exercises)
        in.ignore();
}

Sport::Sport(string s) : TextElement(s.c_str()) {
    exercises = new List(Sorted);
    if (getInt(0, 1, 2, "Write score type, Score = 0, Time = 1") == 0)
        score_type = SportScore(SCORE);
    else
        score_type = SportScore(TIME);
}

Sport::~Sport() {
    delete exercises;
}

void Sport::addExercise(Exercise* exercise) {
    // If unique id taken do nothing and just return
    if (exercises->inList(exercise->getNumber()))
        return;
    // id is unique, adding to list
    exercises->add(exercise);

}

List * Sport::getExercisesList() {
    return exercises;
}

Exercise* Sport::getExercise(int n) {
    Exercise* exercise = (Exercise*)exercises->remove(n);
    // Add it back to list if its not null before returning it
    if (exercise != nullptr)
        exercises->add(exercise);
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
    strcpy_s(text, s.size() + 1, s.c_str());
}

void Sport::writeToFile(std::ofstream& out) {
    Exercise* ex;
    // Name of sport
    out << text << endl;
    // Score type of sport
    out << score_type << endl;
    out << exercises->noOfElements() << endl;
    for (int i = 1; i <= exercises->noOfElements(); i++) {
        ex = (Exercise*)exercises->removeNo(i);
        // Add back to list
        exercises->add(ex);
        // Write exercise id to file
        out << ex->getNumber() << endl;
        // Write exercise class to file
        out << "-------ExerciseBEGIN--------" << endl;
        ex->writeToFile(out);
        out << "-------ExerciseSTOP--------" << endl;
    }
    out << endl;
}
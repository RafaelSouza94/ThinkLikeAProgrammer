#include "student_records.h"

void student_record::set_grade(int new_grade) {
    
    if (is_valid_grade(new_grade)) {
        _grade = new_grade;
    }
}

int student_record::grade() {
    return _grade;
}

void student_record::set_name(string new_name) {
    _name = new_name;
}

string student_record::letter_grade() {

    if (!is_valid_grade(_grade)) return "ERROR";

    const int NUM_CATEGORIES = 11;
    const double GRADE_LETTER[NUM_CATEGORIES] = { 'F', 'D', 'D+', 'C-', 'C+', 'B-', 'B', 'A-', 'A'};
    const double LOWEST_GRADE_SCORE[NUM_CATEGORIES] = { 0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93 };

    int category = 0;

    while (category < NUM_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade) {
        category++;
    }

    return GRADE_LETTER[category - 1];
}

string student_record::name() {
    return _name;
}

void student_record::set_student_id(int new_id) {
    _student = new_id;
}

int student_record::student_id() {
    return _student;
}

bool student_record::is_valid_grade(int grade) {

    if ((new_grade >= 0) && (new_grade <= 100))
        return true;
    else {
        cout << "Invalid grade." << endl;
        return false;
    }
}

student_record::student_record() {
    set_grade(0);
    set_name(" ");
    set_student_id(-1);
}

student_record::student_record(int new_grade, int new_id, string name) {
    set_grade(new_grade);
    set_name(name);
    set_student_id(new_id);
}
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class student_record {

public:
    student_record();
    student_record(int new_grade, int new_id, string new_name);
    int grade();
    void set_grade(int new_grade);
    int student_id();
    void set_student_id(int new_id);
    string name();
    void set_name(string new_name);
    string letter_grade();

private:
    int _grade;
    int _student;
    string _name;

    bool is_valid_grade(int grade);
};
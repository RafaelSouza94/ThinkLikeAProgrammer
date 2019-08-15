#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Chapter3 {

private:
    const int MAX_RESPONSE = 10;
    struct student {
        int grade;
        int student_id;
        string name;
    };

public:
    void finding_mode();
    void insertion_sort (int*, int);
    int* get_histogram (int*, int);
    void license_cost (int, double);
    void highest_grades();
    void highest_sales();
    void dynamic_survey();
};


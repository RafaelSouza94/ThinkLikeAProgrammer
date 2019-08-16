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
   
    student student_array[10] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"}
    };

public:
    void finding_mode();
    void insertion_sort (int*, int);
    int* get_histogram (int*, int);
    void license_cost (int, double);
    void highest_grades();
    void highest_sales();
    void dynamic_survey();
    void three_one ();
};


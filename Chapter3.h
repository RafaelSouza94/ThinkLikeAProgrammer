#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Chapter3 {

private:
    const static int MAX_RESPONSE = 10;
    const static int NUM_AGENTS = 4;
    const static int NUM_MONTHS = 12;
    const static int ALPHABET_SIZE = 26;

    int sales[NUM_AGENTS][NUM_MONTHS] = {
        {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
        {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
        {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };
    struct student {
        int grade;
        int student_id;
        string name;
    };
   
    const char alphabet[ALPHABET_SIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    student student_array[MAX_RESPONSE] = {
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
    void three_two();
    void three_three (int[], int);
    void three_four ();
    void three_five ();
};


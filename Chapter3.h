#pragma once
#include <iostream>

using namespace std;

class Chapter3 {

private:
    const int MAX_RESPONSE = 10;

public:
    void finding_mode();
    void insertion_sort (int*, int);
    int* get_histogram (int*, int);
    void license_cost (int, double);
};


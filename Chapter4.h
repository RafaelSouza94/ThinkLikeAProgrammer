#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Chapter4 {

private:
    typedef char* array_string;
    int length (array_string);


public:
    void test_ref_param ();
    char character_at (array_string, int);
    void append (array_string&, char);
    void append_tester ();
    void concatenate(array_string&, array_string);
    void concatenate_tester();
};


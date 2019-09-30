#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Chapter4 {

private:
    typedef char* array_string;
    int length (array_string);
    struct list_node {
        int student_number;
        int grade;
        list_node next*;
    };
    typedef list_node* student_collection;


public:
    void test_ref_param ();
    char character_at (array_string, int);
    void append (array_string&, char);
    void append_tester ();
    void concatenate(array_string&, array_string);
    void concatenate_tester();
    void linked_list();
    void add_record(student_collection&, int, int);
    double average_record(student_collection);
};


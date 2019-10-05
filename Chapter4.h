#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Chapter4 {

private:
    struct list_node {
        int student_number;
        int grade;
        list_node *next;
    };
    struct string_node {
        char c;
        string_node* next;
    };
    struct int_node {
        int number;
        int_node* next;
    };
    typedef list_node* student_collection;
    typedef char* array_string;
    typedef char* new_array;
    typedef string_node* list_string;
    typedef int_node* list_int;

    void print_list(student_collection);
    void remove_record(student_collection&, int);
    void print_linked(list_string);
    char linked_character_at(list_string, int);
    int length(array_string);
    void print_linked_int(list_int);
    list_int int_to_list(int);

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
    array_string four_two(array_string, int, int);
    void four_three(array_string&, array_string, array_string);
    void four_four();
    void funct1(char*);
    void funct2(char*&);
    void funct3(char); 
    void four_six();
    void linked_append(list_string&, list_string);
    void linked_remove_chars(list_string&, int, int);
    void four_nine();
};


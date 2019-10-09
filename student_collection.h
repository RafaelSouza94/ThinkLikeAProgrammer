#pragma once
#include <iostream>
#include "student_records.h"

using namespace std;

class student_collection {
private:
    struct student_node {
        student_record student_data;
        student_node* next;
    };

public:
    student_collection();
    student_collection(const student_collection& original);
    ~student_collection();
    void add_record(student_record new_student);
    student_record record_with_number(int id_num);
    void remove_record(int id_num);
    student_collection& operator=(const student_collection& rhs);

private:
    typedef student_node* student_list;
    student_list _list_head;
    void delete_list(student_list& list_ptr);
    student_list copied_list(const student_list original);
};
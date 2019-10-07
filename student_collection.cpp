#include "student_collection.h"

student_collection::student_collection() {
    _list_head = NULL;
}

void student_collection::add_record(student_record new_student) {

    student_node* new_node = new student_node;
    new_node->student_data = new_student;
    new_node->next = _list_head;
    _list_head = new_node;
}

student_record student_collection::record_with_number(int id_num){

    student_node* loop_ptr = _list_head;

    while (loop_ptr !=  NULL && loop_ptr->student_data.student_id() != id_num) {
        loop_ptr = loop_ptr->next;
    }

    if (loop_ptr == NULL) {
        student_record dummy_record(-1, -1, "");
        return dummy_record;
    }
    else {
        return loop_ptr->student_data;
    }

}

void student_collection::remove_record(int id_num) {

    student_node* loop_ptr = _list_head;
    student_node* trailing = NULL;
    while (loop_ptr != NULL && loop_ptr->student_data.student_id() != id_num) {
        trailing = loop_ptr;
        loop_ptr = loop_ptr->next
    }

    if (loop_ptr = NULL) return;
    if (trailing == NULL) {
        _list_head = _list_head->next;
    } else {
        trailing->next = loop_ptr->next;
    }
    delete loop_ptr;
}

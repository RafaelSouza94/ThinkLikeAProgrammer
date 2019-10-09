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

void student_collection::delete_list(student_list& list_ptr){

    while (list_ptr != NULL) {
        student_node* temp = list_ptr;
        list_ptr = list_ptr->next;
        delete temp;
    }
}

student_collection::~student_collection(){
    delete_list(_list_head);
}

student_collection::student_list student_collection::copied_list(const student_list original){

    if (original == NULL) return NULL;

    student_list new_list = new student_node;
    new_list->student_data = original->student_data;
    student_node* old_loop_ptr = original->next;
    student_node* new_loop_ptr = new_list;
    while (old_loop_ptr != NULL) {
        new_loop_ptr->next = new student_node;
        new_loop_ptr = new_loop_ptr->next;
        new_loop_ptr->student_data = old_loop_ptr->student_data;
        old_loop_ptr = old_loop_ptr->next;
    }
    new_loop_ptr->next = NULL;
    return new_list;
}

student_collection& student_collection::operator=(const student_collection& rhs){
    
    if (this != &rhs) {
        delete_list(_list_head);
        _list_head = copied_list(rhs._list_head);
    }
    return *this;
}

student_collection::student_collection(const student_collection& original){
    _list_head = copied_list(original._list_head);
}
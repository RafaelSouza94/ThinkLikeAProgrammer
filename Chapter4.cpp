#include "Chapter4.h"

void ref_param_function (int& x) {

    x = 10;
}

void Chapter4::test_ref_param () {

    int number = 5;
    ref_param_function (number);
    cout << number << endl;
}

char Chapter4::character_at (array_string s, int position) { return s[position]; }

void Chapter4::append (array_string& s, char c) {

    int old_length = length(s);

    array_string new_string = new char[old_length + 2];
    for (int i = 0; i < old_length; i++) {
        new_string[i] = s[i];
    }
    new_string[old_length] = c;
    new_string[old_length + 1] = 0;
    delete[] s;
    s = new_string;
}

int Chapter4::length (array_string s) {

    int count = 0;

    while (s[count] != 0) {
        count++;
    }
    return count;
}

void Chapter4::append_tester () {

    Chapter4::array_string a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    append (a, '!');
    cout << a << "\n";

    array_string b = new char[1];
    b[0] = 0;
    append (b, '!');
    cout << b << "\n";
    
}

void Chapter4::concatenate(array_string &s1, array_string s2) {

    int s1_old_length = length(s1);
    int s2_length = length(s2);
    int s1_new_length = s1_old_length + s2_length;
    array_string new_string = new char[s1_new_length + 1];

    for (int i = 0; i < s1_old_length; i++) {
        new_string[i] = s1[i];
    }

    for (int i = 0; i < s2_length; i++) {
        new_string[s1_old_length + i] = s2[i];
    }

    new_string[s1_new_length] = 0;
    delete[] s1;
    s1 = new_string;
}

void Chapter4::concatenate_tester() {

    Chapter4::array_string a = new char[5];
    Chapter4::array_string b = new char[4];
    Chapter4::array_string c = new char[1];
    
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    c[0] = 0;

    /*
    cout << "Input string: " << a << " Concatenate string: " << b << endl;
    concatenate(a, b);
    cout << "New string: " << a << endl;
    */

    cout << "Input string: " << c << " Concatenate string: " << a << endl;
    concatenate(c, a);
    cout << "New string: " << c << endl;
    cout << "Pointers:\na:" << (void*)a << " c: " << (void*)c << endl;
}

void Chapter4::add_record(student_collection& sc, int student_number, int grade) {
    // Adds a new node to the beginning of the list

    list_node* new_node = new list_node;
    new_node->student_number = student_number;
    new_node->grade = grade;
    new_node->next = sc;
    sc = new_node;
}

double Chapter4::average_record(student_collection sc) {

    if (sc == NULL) return 0;

    int count = 0;
    double sum = 0;
    list_node* loop_ptr = sc;

    while (loop_ptr != NULL) {
        sum += loop_ptr->grade;
        count++;
        loop_ptr = loop_ptr->next;
    }

    double average = sum / count;
    return average;
}

void Chapter4::print_list(student_collection sc) {

    list_node* loop_ptr = sc;

    while (loop_ptr != NULL) {
        cout << "Student Number: " << loop_ptr->student_number;
        cout << "\tGrade: " << loop_ptr->grade << endl;
        loop_ptr = loop_ptr->next;
    }
}

void Chapter4::remove_record(student_collection& sc, int number) {

    list_node* loop_ptr = sc;
    list_node* previous_ptr = sc;

    while (loop_ptr != NULL) {
        if (loop_ptr->student_number == number) {
            previous_ptr->next = loop_ptr->next;
            return;
        }
        previous_ptr = loop_ptr;
        loop_ptr = loop_ptr->next;
    }

    delete loop_ptr;
}

void Chapter4::linked_list() {

    Chapter4::student_collection sc;
    list_node* node1 = new list_node;
    list_node* node2 = new list_node;
    list_node* node3 = new list_node;

    node1->student_number = 1001; node1->grade = 78;
    node2->student_number = 1012; node2->grade = 93;
    node3->student_number = 1076; node3->grade = 85;
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;  // To avoid cross-linking   

    cout << "Current list: " << endl;
    print_list(sc);
    cout << endl;
    add_record(sc, 1274, 91);
    cout << "Added record: " << endl;
    print_list(sc);
    cout << endl;
    cout << "Removed record: " << endl;
    remove_record(sc, 1012);
    print_list(sc);
    cout << endl;

    //int avg = average_record(sc);
}

void Chapter4::print_linked(list_string string) {

    string_node* loop_ptr = string;

    while (loop_ptr != NULL) {
        cout << loop_ptr->c;
        loop_ptr = loop_ptr->next;
    }
}

char Chapter4::linked_character_at(list_string string, int position) {

    string_node* loop_ptr = string;
    int counter = 1;

    while (loop_ptr != NULL) {
        if (counter == position) {
            return loop_ptr->c;
        }
        counter++;
        loop_ptr = loop_ptr->next;
    }
}

void Chapter4::linked_append(list_string& source, list_string string) {

    string_node* loop_ptr_source = source;
    string_node* loop_ptr_string = string;
    string_node* new_node = new string_node;

    while (true) {
        if (loop_ptr_source->next != NULL)
            loop_ptr_source = loop_ptr_source->next;
        else
            break;        
    }

    while (loop_ptr_string != NULL) {
        new_node->c = loop_ptr_string->c;
        new_node->next = loop_ptr_string->next;
        loop_ptr_source->next = new_node;
        new_node = new string_node;
        loop_ptr_source = loop_ptr_source->next;
        loop_ptr_string = loop_ptr_string->next;
    }
}

void Chapter4::linked_remove_chars(list_string& source, int position, int length) {

    string_node* next_holder = new string_node;

    while (true) {
        if (position == 0) {
            if (length == 0) {
                delete next_holder;
                return;
            }
            next_holder = source->next;
            source->next = next_holder->next;
            next_holder = new string_node;
            length--;
        }
        else {
            position--;
        }
    }
}

void Chapter4::print_linked_int(list_int integer) {

    int_node* loop_ptr = integer;
    int number = 0;

    for (int i = 1; loop_ptr != NULL; i *= 10) {
        number += (loop_ptr->number * i);
        loop_ptr = loop_ptr->next;
    }

    cout << number;
}

Chapter4::list_int Chapter4::int_to_list(int number_convert) {

    list_int integer;
    int_node* new_node = new int_node;
    int_node* previous_node = new int_node;
    int digit;

    integer = new_node;

    if (number_convert == 0) {
        new_node->number = 0;
        new_node->next = NULL;
        return integer;
    }

    /*digit = number_convert % 10;
    number_convert /= 10;
    new_node->number = digit;
    new_node->next = previous_node;

    digit = number_convert % 10;
    previous_node->number = digit;
    previous_node->next = NULL;

    new_node = previous_node = NULL;*/

    while (number_convert != 0) {
        previous_node->next = new_node;
        digit = number_convert % 10;
        number_convert /= 10;
        new_node->number = digit;
        new_node->next = NULL;
        previous_node = new_node;
        new_node = new int_node;
    }

    new_node = previous_node = NULL;

    cout << "Number: ";
    print_linked_int(integer);
    cout << endl;
    return integer;
}

void Chapter4::four_nine() {

    list_int integer;
    int number_convert;
    list_int int_convert;

    int_node* node1 = new int_node;
    int_node* node2 = new int_node;
    int_node* node3 = new int_node;

    node1->number = 1;
    node2->number = 4;
    node3->number = 9;

    integer = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;

    cout << "Linked number: ";
    print_linked_int(integer);
    cout << endl;   

}

void Chapter4::four_six() {

    list_string string;
    list_string string2;

    string_node* node1 = new string_node;
    string_node* node2 = new string_node;
    string_node* node3 = new string_node;
    string_node* node4 = new string_node;

    string_node* str2_node1 = new string_node;
    string_node* str2_node2 = new string_node;
    string_node* str2_node3 = new string_node;

    node1->c = 't';
    node2->c = 'e';
    node3->c = 's';
    node4->c = 't';

    string = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    node1 = node2 = node3 = node4 = NULL;

    str2_node1->c = 'b';
    str2_node2->c = 'e';
    str2_node3->c = 'd';

    string2 = str2_node1;
    str2_node1->next = str2_node2;
    str2_node2->next = str2_node3;
    str2_node3->next = NULL;
    str2_node1 = str2_node2 = str2_node3 = NULL;

    cout << "String: ";
    print_linked(string);
    cout << endl;
    cout << "Character at 3: ";
    cout << linked_character_at(string, 3);
    cout << endl;
    cout << "Appeding 'bed': ";
    linked_append(string, string2);
    print_linked(string);
    cout << endl;
    cout << "Removing 3 characters from position 2: ";
    linked_remove_chars(string, 2, 3);
    print_linked(string);
    cout << endl;
}

Chapter4::array_string Chapter4::four_two(array_string string, int position, int length) {

    array_string new_string = new char[length + 1];

    for (int i = 0; i < length; i++) {
        //cout << "[DEBUG] i: " << i << " position: " << position << " length: " << length << " string[i+p-1]: " << string[i + (position - 1)] << endl;
        new_string[i] = string[i + (position - 1)];
    }

    new_string[length] = 0;

    return new_string;
}

void Chapter4::four_three(array_string& source, array_string target, array_string replace_text) {

    int length_source = length(source);
    int length_target = length(target);
    int length_replace = length(replace_text);
    int counter = 0;
    int ocurrencies;
    //int array_size;
    vector<int> positions;

    positions.reserve(30);

    cout << "Original string: " << source << endl;

    for (int i = 0; i < length_source; i++) {
        if (source[i] == target[0]) {
            //cout << "Match:\ti: " << i << "\tsource: " << source[i] << "\ttarget: " << target[0] << endl;
            positions.push_back(i);
            for (int j = 1; j < length_target; j++) {
                if (source[i + j] != target[j]) {
                    //cout << "No match" << endl ;
                    break;
                }
                else {
                    //cout << "Match:\ti: " << i << "\tj: " << j << "\tsource: " << source[i + j] << "\ttarget: " << target[j] << endl;
                    positions.push_back(i+j);
                }
            }
        }
    }

    ocurrencies = positions.size() / length_target;
    array_string new_string = new char[ocurrencies]; 
    cout << "ocurrencies: " << ocurrencies << endl;

    for (int i = 0; i < length_source; i++) {
        //cout << "[DEBUG] i: " << i << " source[i]: " << source[i] << endl;
        if (find(positions.begin(), positions.end(), i) != positions.end()) {
            for (int j = 0; j < length_replace; j++) {
                new_string[counter] = replace_text[j];
                //cout << "[DEBUG] Inside the for - i: " << i << " j: " << j << " counter: " << counter << " new_string[i+j]: " << new_string[counter] << " replacetext[j]: " << replace_text[j] << endl;
                counter++;
            }
            i += length_target - 1;
        }
        else {
            new_string[counter] = source[i];
            //cout << "[DEBUG] Inside the else - i: " << i << " counter: " << counter << " new_string[counter]: " << new_string[counter] << " source[i]: " << source[i] << endl;
            counter++;
        }
    }
    
    new_string[counter] = 0;
    delete[] source;
    source = new_string;
    //cout << "New String: " << source << endl;
}

void four_four_output(char * string) {

    int size = string[0];

    for (int i = 1; i <= size; i++) {
        cout << string[i];
    }
}

void four_four_append(char* & string, char c) {

    int length = string[0];
    char* new_string = new char[length];

    for (int i = 1; i <= length; i++) {
        new_string[i] = string[i];
    }

    new_string[0] = length + 1;
    new_string[length + 1] = c;

    delete[] string;
    string = new_string;
}

char four_four_character_at(char *string, int position) { return string[position]; }

void four_four_concatenate(char*& source, char* string) {

    int source_length = source[0];
    int string_length = string[0];
    int final_size = source_length + string_length - 1;
    char* new_string = new char[final_size];

    new_string[0] = final_size;

    for (int i = 1; i <= source_length; i++) {
        new_string[i] = source[i];
    }

    for (int i = 1; i <= string_length; i++) {
        new_string[i + (source_length - 1)] = string[i];
    }

    //delete[] source;
    source = new_string;
}

void Chapter4::four_four() {

    new_array string = new char[5];
    new_array string_2 = new char[4];
    
    string[0] = 4; string[1] = 't'; string[2] = 'e'; string[3] = 's'; string[4] = 't';
    string_2[0] = 3; string_2[1] = 'b'; string_2[2] = 'e'; string_2[3] = 'd';

    cout << "String - Regular: ";
    four_four_output(string);
    cout << endl;
    cout << "String - Added '!': ";
    four_four_append(string, '!');
    four_four_output(string);
    cout << endl;
    cout << "Character at 3: ";
    cout << four_four_character_at(string, 3);
    cout << endl;
    cout << "Concatenating with 'bed': ";
    four_four_concatenate(string, string_2);
    four_four_output(string);
    cout << endl;
}

void Chapter4::funct1(char* ptr) { cout << "Char* ptr: " << &ptr << endl; }

void Chapter4::funct2(char*& ptr) { cout << "Char* &ptr: " << &ptr << endl; }

void Chapter4::funct3(char c) { cout << "Char c: " << c << endl; }

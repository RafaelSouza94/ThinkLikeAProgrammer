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
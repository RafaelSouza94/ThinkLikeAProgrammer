#include "Chapter4.h"

void ref_param_function (int& x) {

    x = 10;
}

void Chapter4::test_ref_param () {

    int number = 5;
    ref_param_function (number);
    cout << number << endl;
}

char Chapter4::character_at (array_string s, int position) {
    return s[position];
}

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
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = '0';
    append (a, '!');
    cout << a << "\n";

    array_string b = new char[1];
    b[0] = 0;
    append (b, '!');
    cout << b << "\n";

}
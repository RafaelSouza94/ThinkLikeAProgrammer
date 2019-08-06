#pragma once
#include <iostream>

using namespace std;

class Chapter2 {

	enum mode_type {
        LOWERCASE,
        UPPERCASE,
        PUNCTUATION
	};

public:
    void half_a_square();
	void sideways_triangle();
	int doubled_digit_value(int);
    void luhns_formula();
    void pos_or_neg();
    void converter(int, mode_type);
    mode_type change_mode(mode_type);
    void cipher();
    void two_one();
    void two_two();
    void two_three();
    void two_four();
    void two_five();
    int decimal_to_binary(int);
    void binary_to_decimal();
    void two_six();
};


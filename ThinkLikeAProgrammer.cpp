// ThinkLikeAProgrammer.cpp : All the code from the Think Like a Programmer book.

#include <iostream>
using namespace std;

enum mode_type {
    LOWERCASE,
    UPPERCASE,
    PUNCTUATION
};

void sideways_triangle() {

    cout << "------------- Sideways triangle problem.\n";
    for (int row = 1; row < 9; row++) {
        for (int hashes = 1; hashes <= 4 - abs(4 - row); hashes++) {
            cout << "#";
        }
        cout << "\n";
    }
    cout << "------------- Finished.\n";
}

void half_a_square() {

    cout << "------------- Half a square problem.\n";
    for (int row = 1; row < 6; row++) {
        for (int hashes = 1; hashes <= 6 - row; hashes++) {
            cout << "#";
        }
        cout << "\n";
    }
    cout << "------------- Finished.\n";
}

int doubled_digit_value(int digit){

    int doubled_digit = 0;
    int sum = 0;

    doubled_digit = digit * 2;
    if (doubled_digit >= 10) {
        sum = 1 + doubled_digit % 10;
    }
    else {
        sum = doubled_digit;
    }
    return sum;
}

void luhns_formula() {

    char digit;
    int odd_checksum = 0;
    int even_checksum = 0;
    int checksum = 0;
    int position = 1;

    cout << "------------- Luhn Checksum Validation problem.\n";
    cout << "Enter a number for validation: ";
    digit = cin.get();
    while (digit != 10){
        if (position % 2 == 0) {
            odd_checksum += doubled_digit_value(digit - '0');
            even_checksum += digit - '0';
        }
        else {
            even_checksum += doubled_digit_value(digit - '0');
            odd_checksum += digit - '0';
        }
        digit = cin.get();
        position++;
    }
 
    if ((position - 1) % 2 == 0) {
        //cout << "[DEBUG] Even checksum\n";
        checksum = even_checksum;
    }
    else {
        //cout << "[DEBUG] Odd checksum\n";
        checksum = odd_checksum;
    }

    cout << "\nChecksum is " << checksum << ".\n";
    if (checksum % 10 == 0) {
        cout << "Checksum is valid.\n";
    }
    else {
        cout << "Checksum is not valid.\n";
    }
    cout << "------------- Finished.\n";
}

void pos_or_neg() {

    int number;
    int pos_count = 0;
    int neg_count = 0;

    cout << "Type 10 numbers, positive or negative: ";
    for (int i = 0; i < 10; i++) {
        cin >> number;
        if (number > 0)
            pos_count++;
        if (number < 0)
            neg_count++;
    }
    char response;
    cout << "Do you want the (p)ositive or (n)egative count? ";
    cin >> response;
    if (response == 'p')
        cout << "Positive count is " << pos_count << ".\n";
    if (response == 'n')
        cout << "Negative count is " << neg_count << ".\n";
}

void converter(int number, mode_type mode) {

    char output_char = ' ';
    if (mode == UPPERCASE) { 
        output_char = number + 'A' - 1;
    } 
    else if (mode == LOWERCASE) { 
        output_char = number + 'a' - 1;
    }
    else if (mode == PUNCTUATION) { 
        switch (number) {
            case 1: 
                output_char = '!';
                break;
            case 2:
                output_char = '?';
                break;
            case 3:
                output_char = ',';
                break;
            case 4:
                output_char = '.';
                break;
            case 5:
                output_char = ' ';
                break;
            case 6:
                output_char = ';';
                break;
            case 7:
                output_char = '"';
                break;
            case 8:
                output_char = '\'';
                break;
            default:
                break;
        }
    }

    cout << output_char;
}

mode_type change_mode(mode_type mode) {

    switch (mode) {
        case UPPERCASE:
            mode = LOWERCASE;
            break;
        case LOWERCASE:
            mode = PUNCTUATION;
            break;
        case PUNCTUATION:
            mode = UPPERCASE;
            break;
    }
    return mode;
}

void cipher() {

    cout << "------------- Decode a Message problem.\n";
    cout << "Enter message to be decoded: ";
    mode_type mode = UPPERCASE;
    char digit_char;
    do {
        digit_char = cin.get();
        int number = (digit_char - '0');
        digit_char = cin.get();
        while ((digit_char != 10) && (digit_char != ',')) {
            number = number * 10 + (digit_char - '0');
            digit_char = cin.get();
        }
        if (mode == PUNCTUATION) {
            number = number % 9;
            if (number == 0) {
                mode = change_mode(mode);
                continue;
            }
            else {
                converter(number, mode);
                continue;
            }
        }
        else {
            number = number % 27;
            if (number == 0) {
                mode = change_mode(mode);
                continue;
            }
            else {
                converter(number, mode);
            }
        }
    } while (digit_char != 10);
}

int main() {

    cout << "Chapter 2 code\n";
    //half_a_square();
    //sideways_triangle();
    
    //luhns_formula();
    //pos_or_neg();

    cipher();
    //converter(3);
    //change_mode();
}



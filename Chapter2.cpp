#include "Chapter2.h"

void Chapter2::sideways_triangle() {

    cout << "------------- Sideways triangle problem.\n";
    for (int row = 1; row < 9; row++) {
        for (int hashes = 1; hashes <= 4 - abs(4 - row); hashes++) {
            cout << "#";
        }
        cout << "\n";
    }
    cout << "------------- Finished.\n";
}

void Chapter2::half_a_square() {

    cout << "------------- Half a square problem.\n";
    for (int row = 1; row < 6; row++) {
        for (int hashes = 1; hashes <= 6 - row; hashes++) {
            cout << "#";
        }
        cout << "\n";
    }
    cout << "------------- Finished.\n";
}

int Chapter2::doubled_digit_value(int digit) {

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

void Chapter2::luhns_formula() {

    char digit;
    int odd_checksum = 0;
    int even_checksum = 0;
    int checksum = 0;
    int position = 1;

    cout << "------------- Luhn Checksum Validation problem.\n";
    cout << "Enter a number for validation: ";
    digit = cin.get();
    while (digit != 10) {
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

void Chapter2::pos_or_neg() {

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

void Chapter2::converter(int number, mode_type mode) {

    const char punctuation[8] = { '!', '?', ',', '.', ' ', ';', '"', '\'' };

    char output_char = ' ';
    if (mode == UPPERCASE) {
        output_char = number + 'A' - 1;
    }
    else if (mode == LOWERCASE) {
        output_char = number + 'a' - 1;
    }
    else if (mode == PUNCTUATION) {
        /* method from chapter 2 - switch
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
        }*/
        /* method from chapter 3 - fixed array */
        output_char = punctuation[number - 1];
    }

    cout << output_char;
}

Chapter2::mode_type Chapter2::change_mode(mode_type mode) {

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

void Chapter2::cipher() {

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

void Chapter2::two_one() {

    cout << "------------- Exercise 2.1.\n";
    for (int counter = 4; counter > 0; counter--) {
        for (int spaces = 4 - counter; spaces > 0; spaces--) {
            cout << " ";
        }
        for (int hashes = counter * 2; hashes > 0; hashes--) {
            cout << "#";
        }
        cout << "\n";
    }
}

void Chapter2::two_two() {

    cout << "------------- Exercise 2.2.\n";
    for (int counter = 1; counter < 5; counter++) {
        for (int spaces = 4 - counter; spaces > 0; spaces--) {
            cout << " ";
        }
        for (int hashes = counter * 2; hashes > 0; hashes--) {
            cout << "#";
        }
        cout << "\n";
    }

    for (int counter = 4; counter > 0; counter--) {
        for (int spaces = 4 - counter; spaces > 0; spaces--) {
            cout << " ";
        }
        for (int hashes = counter * 2; hashes > 0; hashes--) {
            cout << "#";
        }
        cout << "\n";
    }
}

void Chapter2::two_three() {

    cout << "------------- Exercise 2.3.\n";
    int hash_count = 0;
    int space_count = 0;
    for (int counter = 1; counter < 5; counter++) {
        for (int space_1 = counter - 1; space_1 > 0; space_1--) {
            cout << " ";
            space_count = (counter - 1) * 2;
        }
        for (int hash_before = counter; hash_before > 0; hash_before--) {
            cout << "#";
            hash_count = counter * 2;
        }
        for (int space_2 = 14 - hash_count - space_count; space_2 > 0; space_2--) {
            cout << " ";
        }
        for (int hash_after = counter; hash_after > 0; hash_after--) {
            cout << "#";
        }
        for (int space_3 = counter - 1; space_3 > 0; space_3--) {
            cout << " ";
        }
        cout << "\n";
    }

    for (int counter = 4; counter > 0; counter--) {
        space_count = (counter - 1) * 2;
        hash_count = counter * 2;
        for (int space_1 = counter - 1; space_1 > 0; space_1--) {
            cout << " ";
        }
        for (int hash_before = counter; hash_before > 0; hash_before--) {
            cout << "#";
        }
        for (int space_2 = 14 - hash_count - space_count; space_2 > 0; space_2--) {
            cout << " ";
        }
        for (int hash_after = counter; hash_after > 0; hash_after--) {
            cout << "#";
        }
        for (int space_3 = counter - 1; space_3 > 0; space_3--) {
            cout << " ";
        }
        cout << "\n";
    }
}

void Chapter2::two_four() {

    cout << "------------- Exercise 2.4.\n";
    int hash_count = 2;
    int space_count = 0;
    for (int counter = 1; counter < 5; counter++) {
        space_count = (counter - 1) * 2;
        for (int space_1 = counter - 1; space_1 > 0; space_1--) {
            cout << " ";
        }
        cout << "#";
        for (int space_2 = 8 - hash_count - space_count; space_2 > 0; space_2--) {
            cout << " ";
        }
        cout << "#";
        for (int space_3 = counter - 1; space_3 > 0; space_3--) {
            cout << " ";
        }
        cout << "\n";
    }

    hash_count = 2;
    space_count = 0;
    for (int counter = 4; counter > 0; counter--) {
        space_count = (counter - 1) * 2;
        for (int space_1 = counter - 1; space_1 > 0; space_1--) {
            cout << " ";
        }
        cout << "#";
        for (int space_2 = 8 - hash_count - space_count; space_2 > 0; space_2--) {
            cout << " ";
        }
        cout << "#";
        for (int space_3 = counter - 1; space_3 > 0; space_3--) {
            cout << " ";
        }
        cout << "\n";
    }
}

void Chapter2::two_five() {

    cout << "------------- Exercise 2.5.\n";
    cout << "Enter an ISBN number for validation: ";

    int digit;
    int sum = 0;

    for (int position = 1; position <= 13; position++) {
        digit = cin.get() - '0';
        if (position % 2 == 0) {
            sum += digit * 3;
        }
        else {
            sum += digit;
        }
    }

    if (sum % 10 == 0) {
        cout << "ISBN valid.";
    }
    else {
        cout << "ISBN invalid.";
    }
}

int Chapter2::decimal_to_binary(int number) {

    int result = 0;
    int counter = 1;

    while (number > 0) {

        result += (number % 2) * counter;
        number /= 2;
        counter *= 10;
    }
    return result;
}

void Chapter2::two_six() {

    char type;
    int number;

    cout << "------------- Exercise 2.6.\n";
    binary_to_decimal();
    cout << "(B)inary or (D)ecimal? ";
    type = cin.get();

    if (type == 'b') {
        cout << "Enter the number to be converted: ";
        cin >> number;
        cout << "Binary version: " << decimal_to_binary(number) << ".\n";
    }
    else {
        cin.clear();
        binary_to_decimal();
    }
}

void Chapter2::binary_to_decimal() {

    int result = 0;
    int position = 0;
    char digit = '0';

    cout << "Enter the number to be converted: ";

    while (digit != 32) {
        digit = cin.get();
        if (digit == '1') {
            result += pow(2, position);
        }
        position++;
        cout << "Result: " << result << " Position: " << position << endl;
    }

    cout << "Decimal version: " << result << ".\n";
}


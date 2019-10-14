// ThinkLikeAProgrammer.cpp : All the code from the Think Like a Programmer book.

#include <iostream>
#include <cmath>
#include "Chapter2.h"
#include "Chapter3.h"
#include "Chapter4.h"
#include "student_collection.h"
#include "automobile.h"

using namespace std;

int main() {

    Chapter2 ch2 = Chapter2();
    Chapter3 ch3 = Chapter3();
    Chapter4 ch4 = Chapter4();
    //student_collection s;
    automobile car = automobile("Pesadas", "Tretas", 1994);

    /*
    student_record stu_3(84, 1152, "Sue");
    student_record stu_2(75, 4875, "Ed");
    student_record stu_1(98, 2938, "Todd");

    s.add_record(stu_3);
    s.add_record(stu_2);
    s.add_record(stu_1);
    s.remove_record(4875);*/

    cout << "Car: " << car.get_car() << endl;
    cout << "Age: " << car.get_age() << endl;
}

void four_three_input() {
    /*
    char* string = new char[12];
    char* string2 = new char[15];
    char* target = new char[3];
    char* replace = new char[3];
    string[0] = 'a'; string[1] = 'b'; string[2] = 'c'; string[3] = 'd'; string[4] = 'a'; string[5] = 'b'; string[6] = 'e'; string[7] = 'e'; string[8] = 'a', string[9] = 'b', string[10] = 'g';  string[11] = 0;
    string2[0] = 'x'; string2[1] = 'y'; string2[2] = 'z'; string2[3] = 'c'; string2[4] = 'd'; string2[5] = 'x'; string2[6] = 'y'; string2[7] = 'z'; string2[8] = 'e', string2[9] = 'e', string2[10] = 'x';  string2[11] = 'y'; string2[12] = 'z'; string2[13] = 'g'; string2[14] = 0;
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;
    replace[0] = 'x'; replace[1] = 'y'; replace[2] = 'z'; replace[3] = 0;
    ch4.four_three(string2, replace, target);
    cout << "New String: " << string2 << endl;
    */
}



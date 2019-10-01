// ThinkLikeAProgrammer.cpp : All the code from the Think Like a Programmer book.

#include <iostream>
#include <cmath>
#include "Chapter2.h"
#include "Chapter3.h"
#include "Chapter4.h"

using namespace std;

int main() {

    Chapter2 ch2 = Chapter2();
    Chapter3 ch3 = Chapter3();
    Chapter4 ch4 = Chapter4();

    char* string = new char[9];
    char* target = new char[3];
    char* replace = new char[3];
    string[0] = 'a'; string[1] = 'b'; string[2] = 'c'; string[3] = 'd'; string[4] = 'a'; string[5] = 'b'; string[6] = 'e'; string[7] = 'e'; string[8] = 0;
    target[0] = 'a'; target[1] = 'b'; target[2] = 0;
    replace[0] = 'x'; replace[1] = 'y'; replace[2] = 'z'; replace[3] = 0;
    ch4.four_three(string, target, replace);
}



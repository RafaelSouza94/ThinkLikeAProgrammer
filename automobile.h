#pragma once
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

class automobile{

public:
    automobile();
    automobile(string manufacturer, string model, int year);
    ~automobile();
    string get_manufacturer();
    void set_manufacturer(string manufacturer);
    string get_model();
    void set_model(string model);
    int get_year();
    void set_year(int year);
    string get_car();
    int get_age();

private:
    string _manufacturer;
    string _model;
    int _year;

};


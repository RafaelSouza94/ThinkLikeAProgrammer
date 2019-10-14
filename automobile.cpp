#include "automobile.h"

// Constructors & Destructors
automobile::automobile() {

    set_manufacturer("");
    set_model("");
    set_year(-1);
}

automobile::automobile(string manufacturer, string model, int year) {

    set_manufacturer(manufacturer);
    set_model(model);
    set_year(year);
}

automobile::~automobile() {

}


// Getters and Setters
string automobile::get_manufacturer() {
    return _manufacturer;
}

void automobile::set_manufacturer(string manufacturer) {
    _manufacturer = manufacturer;
}

string automobile::get_model() {
    return _model;
}

void automobile::set_model(string model) {
    _model = model;
}

int automobile::get_year() {
    return _year;
}

void automobile::set_year(int year) {
    _year = year;
}


// Helper functions
string automobile::get_car() {

    ostringstream result;
    result << get_year() << " " << get_model() << " " << get_manufacturer();
    return result.str();
}

int automobile::get_age() {

    time_t t = time(NULL);
    tm* time_ptr = new tm;
    localtime_s(time_ptr, &t);

    return (time_ptr->tm_year + 1900) - get_year();
}
//
// Created by Ethan Harrison on 11/25/19.
//

#include "Data.h"
#include <string>
#include <iostream>

using namespace std;

//Overloads the output stream operator
ostream &operator<<(ostream &os, const Data &data) {
    os << data.miles << " Miles" << ", \t" << data.duration << " Seconds" << ", \t" << "$"<< data.price << ", \t" << data.payment;
    return os;
}

//Overloads the comparison operators
bool Data::operator<(const Data &length) const {
    return length.miles < miles;
}

//Overloads the comparison operators
bool Data::operator>(const Data &length) const {
    return miles > length.miles;
}

//Default Constructor
Data::Data(){
    miles = 0.0;
    duration = 0.0;
    price = 0.0;
    payment = " ";
}

//Alternate Constructor
Data::Data(double m, double d, double p, string pay){
    miles = m;
    duration = d;
    price = p;
    payment = pay;
}
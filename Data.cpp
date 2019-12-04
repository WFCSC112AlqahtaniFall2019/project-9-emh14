/* Ethan Harrison
 * CSC 112
 * Project 9
 * Templates and Asymptotic Analysis
 * */

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
    return miles < length.miles;
}

//Overloads the comparison operators
bool Data::operator<=(const Data &length) const {
    return miles <= length.miles;
}

//Overloads the comparison operators
bool Data::operator>(const Data &length) const {
    return miles > length.miles;
}

//Overloads the copy assignment operator
Data& Data::operator=(const Data &copyData){
    Data temp (copyData);

    swap(temp.miles, miles);
    swap(temp.duration, duration);
    swap(temp.price, price);
    swap(temp.payment, payment);

    return *this;
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
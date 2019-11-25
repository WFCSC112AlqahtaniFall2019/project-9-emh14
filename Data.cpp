//
// Created by Ethan Harrison on 11/25/19.
//

#include "Data.h"
#include <string>
#include <iostream>

using namespace std;

//Overloads the output stream operator
ostream &operator<<(ostream &os, const Data &data) {
    os << data.title << ", \t" << data.year << ", \t" << data.score << "/10" << ", \t" << data.runtime << " minutes"
       << ", \t" << data.genre << ", \t"
       << data.rating << endl << endl;
    return os;
}

//Overloads the comparison operators
bool Data::operator<(const Data &scoring) const {
    return scoring.score < score;
}

//Overloads the comparison operators
bool Data::operator>(const Data &scoring) const {
    return score > scoring.score;
}

//Default Constructor
Data::Data(){
    title = " ";
    year = 0;
    score = 0.0;
    runtime = 0;
    genre = " ";
    rating = " ";
}

//Alternate Constructor
Data::Data(string t, int y, double s, int runt, string g, string rate){
    title = t;
    year = y;
    score = s;
    runtime = runt;
    genre = g;
    rating = rate;
}
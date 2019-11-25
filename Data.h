//
// Created by Ethan Harrison on 11/25/19.
//

#ifndef PROJECT9_DATA_H
#define PROJECT9_DATA_H
#include <iostream>
#include <string>
using namespace std;

class Data {

private:
    string title;
    int year;
    double score;
    int runtime;
    string genre;
    string rating;

public:
    //Overloads the output stream operator
    friend ostream& operator<<(ostream& os, const Data& data);

    //Overloads the comparison operators
    bool operator<(const Data &scoring) const;

    //Overloads the comparison operators
    bool operator>(const Data &scoring) const;

    //Default Constructor
    Data();

    //Alternate Constructor
    Data(string t, int y, double s, int runt, string g, string rate);

};


#endif //PROJECT9_DATA_H

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
    double miles;
    double duration;
    double price;
    string payment;

public:
    //Overloads the output stream operator
    friend ostream& operator<<(ostream& os, const Data& data);

    //Overloads the comparison operators
    bool operator<(const Data &length) const;

    //Overloads the comparison operators
    bool operator<=(const Data &length) const;

    //Overloads the comparison operators
    bool operator>(const Data &length) const;

    //Overloads the copy assignment operator
    Data & operator=(const Data &copyData);

    //Default Constructor
    Data();

    //Alternate Constructor
    Data(double m, double d, double p, string pay);

    };


#endif //PROJECT9_DATA_H

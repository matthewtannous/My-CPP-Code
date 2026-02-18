#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

using namespace std;

const int MAX_DEGREE = 100;
typedef double CoefType;

class Polynomial
{
public:
    void read(istream &in);
    void display(ostream &out) const;

    Polynomial operator+(const Polynomial &other);
    Polynomial operator*(const Polynomial &other);
    CoefType evaluate(double value) const;

private:
    int myDegree; 
    CoefType myCoef[MAX_DEGREE + 1]; // +1 to count degree 0
    // myCoef is from 0 to myDegree included
    // myDegree = size - 1
};

istream &operator>>(istream &in, Polynomial &p);
ostream &operator<<(ostream &out, const Polynomial &p);

#endif

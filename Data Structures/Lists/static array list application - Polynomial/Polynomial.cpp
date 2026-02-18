#include "Polynomial.h"
#include <iostream>

using namespace std;

void Polynomial::read(istream &in)
{
    do
    {
        cout << "Enter degree: ";
        in >> myDegree;
        if (myDegree < 0)
        {
            cout << "Degree cannot be negative\n";
        }
    } while (myDegree < 0);

    cout << "Enter polynomial starting from degree 0 in ascending and separated by spaces or newlines:\n";
    for (int i = 0; i <= myDegree; i++)
    {
        in >> myCoef[i];
    }

    for (int i = myDegree; i >= 0; i--)
    {
        if (myCoef[i] != 0)
            break;

        myDegree--;
    }
}

void Polynomial::display(ostream &out) const
{
    out << myCoef[myDegree] << "x^" << myDegree;
    for (int i = myDegree - 1; i > 0; i--)
    {
        if (myCoef[i] > 0)
            out << " + " << myCoef[i] << "x^" << i;
        else if (myCoef[i] < 0)
            out << myCoef[i] << "x^" << i;
    }
    if (myCoef[0] > 0)
        out << " + " << myCoef[0];
    else if (myCoef[0] < 0)
        out << myCoef[0];

    // // Testing version
    // for (int i = 0; i <= myDegree; i++)
    // {
    //     out << myCoef[i] << "x^" << i << " + ";
    // }
    out << endl;
}

Polynomial Polynomial::operator+(const Polynomial &other)
{
    // Create new Rational as a copy of largest (biggest degree)
    if (myDegree > other.myDegree)
    {
        Polynomial result = *this;
        for (int i = 0; i <= other.myDegree; i++)
        {
            result.myCoef[i] += other.myCoef[i];
        }
        return result;
    }
    {
        Polynomial result = other;
        for (int i = 0; i <= myDegree; i++)
        {
            result.myCoef[i] += myCoef[i];
        }
        // Check if largest degrees are 0 to decrement myDegree (executed only if myDegree == other.myDegree)

        for (int i = result.myDegree; i >= 0; i--)
        {
            if (result.myCoef[i] != 0)
            {
                break;
            }
            result.myDegree--;
        }
        return result;
    }
}

Polynomial Polynomial::operator*(const Polynomial &other)
{
    Polynomial result;
    result.myDegree = myDegree + other.myDegree;
    // set result array to 0's
    for (int i = 0; i <= result.myDegree; i++)
    {
        result.myCoef[i] = 0;
    }

    // Each coef in this has to multiply each coef in other
    for (int thisCoef = 0; thisCoef <= myDegree; thisCoef++)
    {
        for (int otherCoef = 0; otherCoef <= other.myDegree; otherCoef++)
        {
            result.myCoef[thisCoef + otherCoef] += myCoef[thisCoef] * other.myCoef[otherCoef];
        }
    }

    return result;
}

CoefType Polynomial::evaluate(double value) const
{
    CoefType result = 0,
             factor = 1;

    for (int i = 0; i <= myDegree; i++)
    {
        result += myCoef[i] * factor;
        factor *= value;
    }
    return result;
}

istream &operator>>(istream &in, Polynomial &p)
{
    p.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Polynomial &p)
{
    p.display(out);
    return out;
}

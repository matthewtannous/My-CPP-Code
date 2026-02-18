/*-- Time.h --------------------------------------------------------

  This header file defines the data type Time for processing time.
  Basic Operations are:
    Default contructor: Initializes object to 12:00 AM
    Explicit-value constructor
    read:       To read a time
    display:    To display the time
    <<, >> :    Input and Output operators
    accessors:  getHours, getMinutes, getAMPM, getMilTime
    set:        to set the time
    advance:    To advance the time by a certain amount
    relops:     <, >, ==, <=, >=, !=

---------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#ifndef TIME_H
#define TIME_H

class Time
{
public:
    // Constructors
    Time();
    Time(unsigned hours, unsigned minutes, char am_pm);

    // Accessors
    unsigned getHours() const;
    unsigned getMinutes() const;
    unsigned getAMPM() const;
    unsigned getMilTime() const;

    // Input and Output operations
    void display(ostream &out) const;
    void read(istream &in);

    // Set operation
    void set(unsigned hours, unsigned minutes, char am_pm);

    // Increment operation
    void advance(unsigned hours, unsigned minutes);

private:
    unsigned myHours,
        myMinutes;
    char myAMorPM;      // 'A' or 'P'
    unsigned myMilTime; // military time equivalent
};

/* << and >>
  We use & when declaring these 2 operators because we want to return them
  by reference, not by value so that they can be chained.

  without &, we are returning a copy of the out or in object sent by the
  method which is wrong. We should reuse the same operator.
*/
ostream &operator<<(ostream &out, const Time &t);
istream &operator>>(istream &in, Time &t);

// Relational operators
bool operator<(const Time &t1, const Time &t2);
bool operator>(const Time &t1, const Time &t2);
bool operator<=(const Time &t1, const Time &t2);
bool operator>=(const Time &t1, const Time &t2);
bool operator==(const Time &t1, const Time &t2);
bool operator!=(const Time &t1, const Time &t2);

#endif

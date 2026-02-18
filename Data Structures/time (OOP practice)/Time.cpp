#include <iostream>
#include "Time.h"

using namespace std;

int getMilitaryTime(const Time &t);

/* Constructors */
Time::Time()
{
    set(12, 0, 'A');
}

Time::Time(unsigned initHours, unsigned initMinutes, char initAMPM)
{
    set(initHours, initMinutes, initAMPM);
}

/* Accessors */
unsigned Time::getHours() const
{
    return myHours;
}

unsigned Time::getMinutes() const
{
    return myMinutes;
}

unsigned Time::getAMPM() const
{
    return myAMorPM;
}

unsigned Time::getMilTime() const
{
    return myMilTime;
}

/*   Input / Output   */
void Time::display(ostream &out) const
{
    out << "Time: "
        << (myHours < 10 ? "0" : "") << myHours
        << ":"
        << (myMinutes < 10 ? "0" : "") << myMinutes
        << " " << myAMorPM
        << "M. Military Time: " << myMilTime << endl;
}

void Time::read(istream &in)
{
    unsigned hours, minutes;
    char AMPM;

    in >> hours >> minutes >> AMPM;
    set(hours, minutes, AMPM);
}

/* Set operation */
void Time::set(unsigned hours, unsigned minutes, char am_pm)
{
    if (hours <= 12)
    {
        myHours = hours;
    }
    else
    {
        myHours = 12;
    }

    if (minutes < 60)
    {
        myMinutes = minutes;
    }
    else
    {
        myMinutes = 0;
    }

    if (am_pm == 'A' || am_pm == 'P')
    {
        myAMorPM = am_pm;
    }
    else
    {
        myAMorPM = 'P';
    }

    myMilTime = getMilitaryTime(*this);
}

void Time::advance(unsigned hours, unsigned minutes)
{
    // Bad but idc
    myHours += hours;
    myMinutes += minutes;
}

ostream &operator<<(ostream &out, const Time &t)
{
    t.display(out);
    return out;
}

istream &operator>>(istream &in, Time &t)
{
    t.read(in);
    return in;
}

bool operator<(const Time &t1, const Time &t2)
{
    return t1.getMilTime() < t2.getMilTime();
}
bool operator>(const Time &t1, const Time &t2)
{
    return t1.getMilTime() > t2.getMilTime();
}
bool operator<=(const Time &t1, const Time &t2)
{
    return t1.getMilTime() <= t2.getMilTime();
}
bool operator>=(const Time &t1, const Time &t2)
{
    return t1.getMilTime() >= t2.getMilTime();
}
bool operator==(const Time &t1, const Time &t2)
{
    return t1.getMilTime() == t2.getMilTime();
}
bool operator!=(const Time &t1, const Time &t2)
{
    return t1.getMilTime() != t2.getMilTime();
}

/* Get military time of time object */
int getMilitaryTime(const Time &t)
{
    int i = t.getHours() * 100 + t.getMinutes();
    if (t.getAMPM() == 'A')
    {
        return i;
    }
    return 2 * i;
}

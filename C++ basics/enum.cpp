#include <iostream>

using namespace std;

int main()
{
    enum status
    {
        OFF = 0,
        ON = 1,
        STANDBY = '1',
    };

    cout << ON << endl;

    enum dayOfWeek
    {
        SUNDAY = 0,
        MONDAY = 1,
        TUESDAY = 2,
        WEDNESDAY = 3,
        THURSDAY = 4,
        FRIDAY = 5,
        SATURDAY = 6,
    };

    int day = 69;

    if (day == SUNDAY || day == SATURDAY)
    {
        cout << "Weekend!!";
    }
    else if (day > SUNDAY && day < SATURDAY)
    {
        cout << "work day";
    }
    else
    {
        cout << "???????????";
    }

    return 0;
}

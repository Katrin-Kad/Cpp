#include <iostream>

using namespace std;

class Time {
private:
    int Hours;
    int Minutes;
    int Seconds;

public:
    static const int HOURS_IN_DAY = 24;
    static const int MINUTES_IN_HOUR = 60;
    static const int SECONDS_IN_MINUTE = 60;

    class InvalidTimeException {
    public:
        string message;
        InvalidTimeException(string mes) {
            message = mes;
        }
    };

    Time() {
        Hours = 0;
        Minutes = 0;
        Seconds = 0;
    }

    Time(int hours, int minutes, int seconds) {
        if (hours >= HOURS_IN_DAY || minutes >= MINUTES_IN_HOUR || seconds >= SECONDS_IN_MINUTE) {
            throw InvalidTimeException("Передано не корректное значение времени");
        }

        Hours = hours;
        Minutes = minutes;
        Seconds = seconds;
    }

    void Print() {
        cout << Hours << ":" << Minutes << ":" << Seconds << endl;
    }

    static Time Add(Time t1, Time t2) {
        int hours = t1.Hours + t2.Hours;
        int minutes = t1.Minutes + t2.Minutes;
        int seconds = t1.Seconds + t2.Seconds;

        minutes += seconds / SECONDS_IN_MINUTE;
        hours += minutes / MINUTES_IN_HOUR;

        seconds %= SECONDS_IN_MINUTE;
        minutes %= MINUTES_IN_HOUR;
        hours %= HOURS_IN_DAY;

        Time newTime{ hours, minutes, seconds };
        return newTime;
    }
};

int main()
{
    int hours, minutes, seconds;
    cout << "Введите первое время - часы, минуты и секунды: ";
    cin >> hours >> minutes >> seconds;
    Time* firstTime;
    try {
        firstTime = new Time(hours, minutes, seconds);
    }
    catch (Time::InvalidTimeException ex) {
        cerr << ex.message;
        return 1;
    }

    cout << "Введите второе время -, минуты и секунды: ";
    cin >> hours >> minutes >> seconds;
    Time* secondTime;
    try {
        secondTime = new Time(hours, minutes, seconds);
    }
    catch (Time::InvalidTimeException ex) {
        cerr << ex.message;
        return 1;
    }

    Time sum = Time::Add(*firstTime, *secondTime);
    sum.Print();
}

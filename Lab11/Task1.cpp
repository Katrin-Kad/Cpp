#include <string>
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

    static int getTotalSeconds(const Time &time) {
        return (time.Hours * MINUTES_IN_HOUR + time.Minutes) * SECONDS_IN_MINUTE + time.Seconds;
    }

    void Print() {
        cout << Hours << ":" << Minutes << ":" << Seconds << endl;
    }

    Time operator+(const Time &time) {
        int hours = Hours + time.Hours;
        int minutes = Minutes + time.Minutes;
        int seconds = Seconds + time.Seconds;

        minutes += seconds / SECONDS_IN_MINUTE;
        hours += minutes / MINUTES_IN_HOUR;

        seconds %= SECONDS_IN_MINUTE;
        minutes %= MINUTES_IN_HOUR;
        hours %= HOURS_IN_DAY;

        Time newTime(hours, minutes, seconds);
        return newTime;
    }

    Time operator+(const int &sec) {
        int hours = Hours;
        int minutes = Minutes;
        int seconds = Seconds + sec;

        minutes += seconds / SECONDS_IN_MINUTE;
        hours += minutes / MINUTES_IN_HOUR;

        seconds %= SECONDS_IN_MINUTE;
        minutes %= MINUTES_IN_HOUR;
        hours %= HOURS_IN_DAY;

        Time newTime(hours, minutes, seconds);
        return newTime;
    }

    Time operator-(const Time &time) {
        int hours = Hours - time.Hours;
        int minutes = Minutes - time.Minutes;
        int seconds = Seconds - time.Seconds;

        minutes += seconds / SECONDS_IN_MINUTE;
        hours += minutes / MINUTES_IN_HOUR;

        seconds %= SECONDS_IN_MINUTE;
        minutes %= MINUTES_IN_HOUR;
        hours %= HOURS_IN_DAY;

        if (seconds < 0) {
            seconds += SECONDS_IN_MINUTE;
            minutes--;
        }
        if (minutes < 0) {
            minutes += MINUTES_IN_HOUR;
            hours--;
        }
        if (hours < 0) hours += HOURS_IN_DAY;

        Time newTime(hours, minutes, seconds);
        return newTime;
    }

    bool operator==(const Time &time) const {
        return Time::getTotalSeconds(*this) == Time::getTotalSeconds(time);
    }

    bool operator!=(const Time &time) const {
        return Time::getTotalSeconds(*this) != Time::getTotalSeconds(time);
    }

    bool operator>(const Time &time) const {
        return Time::getTotalSeconds(*this) > Time::getTotalSeconds(time);
    }

    bool operator<(const Time &time) const {
        return Time::getTotalSeconds(*this) < Time::getTotalSeconds(time);
    }
};

int operator+(const int &sec, const Time &time) {
    return Time::getTotalSeconds(time) + sec;
}


int main() {
    int hours, minutes, seconds;
    cout << "Введите первое время - часы, минуты и секунды: ";
    cin >> hours >> minutes >> seconds;
    Time *firstTime;
    try {
        firstTime = new Time(hours, minutes, seconds);
    }
    catch (Time::InvalidTimeException ex) {
        cerr << ex.message;
        return 1;
    }

    cout << "Введите второе время -, минуты и секунды: ";
    cin >> hours >> minutes >> seconds;
    Time *secondTime;
    try {
        secondTime = new Time(hours, minutes, seconds);
    }
    catch (Time::InvalidTimeException ex) {
        cerr << ex.message;
        return 1;
    }

    Time sum = *firstTime + *secondTime;
    cout << "+: ";
    sum.Print();

    Time diff = *firstTime - *secondTime;
    cout << "-: ";
    diff.Print();

    Time sumInt = *firstTime + 5;
    cout << "+ 5 (sec): ";
    sumInt.Print();

    int intSum = 5 + *firstTime;
    cout << "5 + time: " << intSum << endl;

    cout << "==: " << (*firstTime == *secondTime) << endl;
    cout << "!=: " << (*firstTime != *secondTime) << endl;
    cout << ">: " << (*firstTime > *secondTime) << endl;
    cout << "<: " << (*firstTime < *secondTime) << endl;
}

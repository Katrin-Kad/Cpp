#include <iostream>

using namespace std;

struct Time {
    const int HOURS_IN_DAY = 24;
    const int MINUTES_IN_HOUR = 60;
    const int SECONDS_IN_MINUTE = 60;

    int Hours;
    int Minutes;
    int Seconds;

    Time(int hours, int minutes, int seconds) {
        Hours = hours;
        Minutes = minutes;
        Seconds = seconds;
    }

    Time Add(Time time) {
        int hours = Hours + time.Hours;
        int minutes = Minutes + time.Minutes;
        int seconds = Seconds + time.Seconds;

        minutes += seconds / SECONDS_IN_MINUTE;
        hours += minutes / MINUTES_IN_HOUR;

        seconds %= SECONDS_IN_MINUTE;
        minutes %= MINUTES_IN_HOUR;
        hours %= HOURS_IN_DAY;

        Time newTime (hours, minutes, seconds);
        return newTime;
    }

    Time Diff(Time time) {
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

    void Print() {
        cout << Hours << ":" << Minutes << ":" << Seconds << endl;
    }
};



int main()
{
    int hours, minutes, seconds;
    cout << "Введите первое время - часы, минуты и секунды: ";
    cin >> hours >> minutes >> seconds;
    Time firstTime(hours, minutes, seconds);

    cout << "Введите второе время -, минуты и секунды: ";
    cin >> hours >> minutes >> seconds;
    Time secondTime(hours, minutes, seconds);

    Time sum = firstTime.Add(secondTime);
    sum.Print();

    Time diff = firstTime.Diff(secondTime);
    diff.Print();
}
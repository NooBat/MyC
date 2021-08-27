#ifndef _TIME
#define _TIME

#include<iostream>
#include<string>

using namespace std;

class Time {
private:
    int hour;
    int minute;

public:
    Time();

    Time(const int& hour, const int& minute);

    bool setHour(const int& hour);

    bool setMinute(const int&minute);

    int getHour() const;

    int getMinute() const;

    void increaseTime(const int& givenMinute);

    void display12() const;

    void display24() const;
};

Time::Time(): hour(0), minute(0) {
}

Time::Time(const int& hour, const int& minute) {
    this->setHour(hour);
    this->setMinute(minute);
}

bool Time::setHour(const int& hour) {
    if (hour > 23 || hour < 0) return false;

    this->hour = hour;

    return true;
}

bool Time::setMinute(const int& minute) {
    if (minute > 59 || minute < 0) return false;

    this->minute = minute;

    return true;
}

int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

void Time::increaseTime(const int& givenMinute) {
    int newMinute = getMinute() + givenMinute;

    int hourIncrement = 0;
    
    while (newMinute > 59) {
        newMinute -= 60;
        hourIncrement++;
    }

    setMinute(newMinute);

    int newHour = getHour() + hourIncrement;

    while (newHour > 23) {
        newHour -= 24;
    }

    setHour(newHour);
}

void Time::display12() const {
    string s1;
    string s2 = to_string(getMinute());
    string s3;

    if (getHour() <= 12) {
        s1 = to_string(getHour());
        s3 = "A.M";
    }
    else {
        s1 = to_string(getHour() - 12);
        s3 = "P.M";
    }

    if (s1.length() == 1) {
        s1 = "0" + s1;
    }

    if (s2.length() == 1) {
        s2 = "0" + s2;
    }

    cout << s1 << ":" << s2 << " " << s3;      //prints hh:mm A.M
}

void Time::display24() const {
    string s1 = to_string(getHour());
    string s2 = to_string(getMinute());

    if (s1.length() == 1) {
        s1 = "0" + s1;
    }

    if (s2.length() == 1) {
        s2 = "0" + s2;
    }

    cout << s1 << ":" << s2;    
}
#endif
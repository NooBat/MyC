#ifndef CALENDAR_DATE
#define CALENDAR_DATE

#include<iostream>
#include<string>

using namespace std;



class Calendar {
private:
    int day;
    int month;
    int year;

    const string monthsOfYear[12] = {"January", "February", "March", "April", "May",
                                     "June", "July", "August", "September", "October",
                                     "November", "December"};

    const int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 
                               31, 31, 30, 31, 30, 31};

    bool checkYear() const;
    string getNameOfDay() const;
public:
    Calendar();

    Calendar(const int& day, const int& month, const int& year);

    bool setDay(const int& day);

    bool setMonth(const int& month);

    bool setYear(const int& month);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void displayDate() const;

    void increaseDay();
};

bool Calendar::checkYear() const {
    if (this->year % 100 == 0) {
        if (this->year % 400 == 0) return true;
    }
    else {
        if (this->year % 4 == 0) return true;
    }

    return false;
}

string Calendar::getNameOfDay() const {
    const int centuryCode[4] = {6, 4, 2, 0};

    const int monthCode[12] = {0, 3, 3, 6, 1, 4,
                         6, 2, 5, 0, 3, 5};

    const string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                            "Thursday", "Friday", "Saturday"};

    int nameCode;

    int YY = this->year % 100;

    int yearCode = (YY + (YY / 4)) % 7;

    nameCode = yearCode + monthCode[month - 1] + centuryCode[(year / 100) % 4] + day;

    if (checkYear() && (month == 1 || month == 2)) {
        nameCode--;
    }

    return daysOfWeek[nameCode % 7];
}

Calendar::Calendar(): day(1), month(1), year(0) {
}

Calendar::Calendar(const int& day, const int& month, const int& year) {
    this->setYear(year);
    this->setMonth(month);
    this->setDay(day);
}

bool Calendar::setDay(const int& day) {
    if (day <= 0) return false;

    if (checkYear() && getMonth() == 2) {
        if (day > 29) return false;
    }
    else {
        if (day > daysOfMonth[getMonth() - 1]) return false;
    }

    this->day = day;

    return true;
}

bool Calendar::setMonth(const int& month) {
    if (month <= 0 || month > 12) return false;

    this->month = month;

    return true;
}

bool Calendar::setYear(const int& year) {
    if (year < 0) return false;

    this->year = year;

    return true;
}

int Calendar::getDay() const {
    return this->day;
}

int Calendar::getMonth() const {
    return this->month;
}

int Calendar::getYear() const {
    return this->year;
}

void Calendar::displayDate() const {
    string s1 = getNameOfDay();
    string s2 = to_string(day);
    string s3 = monthsOfYear[getMonth() - 1];
    string s4 = to_string(year);



    cout << s1 << " " << s3 + " " + s2 + ", " + s4;
}

void Calendar::increaseDay() {
    if (day == 31 && month == 12) {
        day = 1;
        month = 1;
        year++;
    }
    else if (day == 29 && month == 2) {
        day = 1;
        month++;
    }
    else if (day == daysOfMonth[month - 1]) {
        day = 1;
        month++;
    }
    else {
        day++;
    }
}

#endif
#include<bits/stdc++.h>

//[Q1.2]
class Integer {
private:
    int val;

public:
    Integer() {
          
    }
    
    Integer(const int& val) {
        setValue(val);
    }
    
    void setValue(const int& val) {
        this->val = val;
    }
    
    int getValue() const {
        return val;
    }
};


//[Q1.3]
class Room {
private:
    double length;
    double breadth;
    double height;

public:
    Room() {
        length = 0;
        breadth = 0;
        height = 0;
    }
    
    Room(const double& length, const double& breadth, const double& height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }
    
    double calculateArea() const {
        return length * breadth;
    }
    
    double calculateVolume() const {
        return length * breadth * height;
    }
};


//[Q1.4]
class ClockType
{
public:
    ClockType(int, int, int); //constructor with parameters
    ClockType(); //default constructor
    
    void printTime() const;
    void setTime(int, int, int);
    void getTime(int&, int&, int&) const;

private:
    int hr;
    int min;
    int sec;
};

ClockType::ClockType() {
    hr = 0;
    min = 0;
    sec = 0;
}

ClockType::ClockType(int hr, int min, int sec) {
    if (hr < 0 || hr >= 24) hr = 0;
    if (min < 0 || min >= 60) min = 0;
    if (sec < 0 || sec >= 60) sec = 0;
    
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}


//[Q1.5]
void ClockType::setTime(int hr, int min, int sec) {
    if (hr < 0 || hr >= 24) hr = 0;
    if (min < 0 || min >= 60) min = 0;
    if (sec < 0 || sec >= 60) sec = 0;
    
    this->hr = hr;
    this->min = min;
    this->sec = sec;
}


//[Q1.13]
template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T & value);
    T getAt(int idx);
    T& operator[](int idx);
    
    void print();

private:
    int size;
    T * p;
};

template<typename T>
T& Array<T>::operator[](int idx) {
    if (idx < 0 || idx >= size) throw -1;
    
    return p[idx];
}


//[Q1.6]
void ClockType::getTime(int& hr, int& min, int& sec) const {
    hr = this->hr;
    min = this->min;
    sec = this->sec;
}


//[Q1.17]
class Course {
    private:
        int ID;
        int numOfStudent;
        int numOfTeacher;
        int numOfTA;
    public:
        void getinfo();
        void disinfo();
};

void Course::getinfo() {
   cout << "ID: ";
   cin >> ID;
   cout << "Number of Students: ";
   cin >> numOfStudent;
   cout << "Number of Teachers: ";
   cin >> numOfTeacher;
   cout << "Number of TAs: ";
   cin >> numOfTA;
}

void Course::disinfo()
{
   cout<<endl;
   cout<< "CourseID = "<< ID << endl;
   cout<< "Number of student = " << numOfStudent << endl;
   cout<< "Number of teacher = " << numOfTeacher << endl;
   cout<< "Number of TA = " << numOfTA<< endl;
}


int main() {
    //TODO
    int n;
    cin >> n;
    Course* courseArr = new Course[n];
    
    for (int i = 0; i < n; i++) {
        courseArr[i].getinfo();
    }
    
    for (int i = 0; i < n; i++) {
        courseArr[i].disinfo();
    }
    
    return 0;
}
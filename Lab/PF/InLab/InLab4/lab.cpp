#include<bits/stdc++.h>

class ClockType
{
   public:
      void setTime(int, int, int);
      void printTime() const;
      void incrementSeconds();
      void incrementMinutes();
      void incrementHours();
      bool equalTime(const ClockType&) const;
      ClockType(int, int, int);
      ClockType();

   private:
      int hr;
      int min;
      int sec;
};

void ClockType::printTime() const
{
   if (hr < 10)
      cout << "0";
   cout << hr << ":";
   if (min < 10)
      cout << "0";
   cout << min << ":";
   if (sec < 10)
      cout << "0";
   cout << sec;
}

// TODO
//[Q1.8]
void ClockType::incrementSeconds() {
    if (sec == 59) {
        sec = 0;
        incrementMinutes();
    }
    else {
        sec++;
    }
}

void ClockType::incrementMinutes() {
    if (min == 59) {
        min = 0;
        incrementHours();
    } else {
        min++;
    }
}

void ClockType::incrementHours() {
    if (hr == 23) {
        hr = 0;
    }
    else {
        hr++;
    }
}


//[Q1.1]
template<class T> 
class Cell {
protected:
    T infor;
public:
    void set(T _infor) { this->infor = _infor; };
    T get() { return this->infor; };
};

enum Color {White, Yellow, Black, Red, Blue};

template<class T>
class ColoredCell : public Cell<T> {
private:
    T color;

public:
    void setColor(T color) {
        this->color = color;
    }
    
    T getColor() {
        return color;
    }
    
    T* get() {
        if (this->color != White) {
            T* infor = new T();
            *infor = Cell<T>::get();
            return infor;
        }
        return nullptr;
    }
};


//[Q1.7]
bool ClockType::equalTime(const ClockType& other) const {
    if (this->hr == other.hr &&
        this->min == other.min &&
        this->sec == other.sec) return true;
    return false;
}


//[Q1.9]
template <typename T>
class Array {
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> & other); // Copy constructor
    Array<T> & operator=(const Array<T> & other); // Copy assignment operator

    void print();
    
private:
    int size;
    T * p;
};

// TODO
template<typename T>
Array<T>::Array(int size, T initValue) {
    this->p = new T[size];
    
    for (int i = 0; i < size; i++) {
        p[i] = initValue;
    }
    
    this->size = size;
}

template<typename T>
Array<T>::~Array() {
    delete[] p;
    size = 0;
}

template<typename T>
void Array<T>::print() {
    for (int i = 0; i < this->size; ++i) {
        cout << (i > 0 ? " " : "") << this->p[i];
    }
    cout << endl;
}


//[Q1.10]
template<typename T>
Array<T>::Array(const Array<T>& other)
{
    this->size = other.size;
    
    this->p = new T[this->size];
    
    for (int i = 0; i < this->size; i++) {
        this->p[i] = other.p[i];
    }
}


//[Q1.11]
class Book {
    char* name;
public:
    Book(const char*);
    ~Book();
    
    void display();
    char* getName();
};

void Book::display() {
    cout << "Book: " << this->name << endl;
}

char* Book::getName() {
    return this->name;
}

// TODO: Book and ~Book
Book::Book(const char* name) {
    int size = strlen(name);
    
    this->name = new char[size + 1];
    
    for (int i = 0; i < size; i++) {
        this->name[i] = name[i];
    }   
    this->name[size] = '\0';
}

Book::~Book() {
    delete[] name;
    name = nullptr;
}


//[Q1.12]
class Integer {
private:
    int val;
    
public:
    Integer(const int&);
    Integer(Integer*);
    
    Integer operator+(const Integer&) const;
    Integer operator+(const int&) const;
    
    void print();
};

void Integer::print() {
    cout << this->val << endl;
}

Integer::Integer(const int& a) {
    this->val = a;
}

Integer::Integer(Integer* other) {
    this->val = other->val;
}

Integer Integer::operator+(const Integer& other) const {
    return Integer(this->val + other.val);
}

Integer Integer::operator+(const int& other) const {
    return Integer(this->val + other);
}


//[Q1.15]
template<typename T>
Array<T>::Array(const Array<T>& other) {
    cout << "Call copy constructor" << endl;
    
    this->size = other.size;
    
    this->p = new T[this->size];
    
    for (int i = 0; i < this->size; i++) {
        this->p[i] = other.p[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    cout << "Call assignment operator" << endl;
    
    if (!p) delete[] this->p;
    
    this->size = other.size;
    
    this-> p = new T[this->size];
    
    for (int i = 0; i < this->size; i++) {
        this->p[i] = other.p[i];
    }
    
    return *this;
}
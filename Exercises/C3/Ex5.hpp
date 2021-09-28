#ifndef _TRIANGLE
#define _TRIANGLE

class Triangle {
private:
    double sides[3];    //contains data of 3 sides
    double angles[3];   //contains data of 3 angles

public:
    Triangle();

    Triangle(double sides[], double angles[]);

    bool setSides(double sides[]);

    bool setAngles(double angles[]);

    void getSides() const;

    void getAngles() const;

    double getArea() const;

    
};
#endif
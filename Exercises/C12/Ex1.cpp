#include<iostream>

using namespace std;

class Sphere
{
private:
    double radius;
public:
    Sphere()
    {
        radius = 0.0;
    }

    Sphere(double radius)
    {
        this->radius = radius;
    }

    double getRadius() const
    {
        return radius;
    }

    double getArea() const 
    {
        return radius * radius * 4 * 3.14;
    }

    void displayStatistics() const
    {
        cout << "Area of the sphere is " << getArea() << endl;
    }

};

class Ball : public Sphere
{
public:
    Ball() : Sphere(0)
    {

    }

    Ball(double radius) : Sphere(radius)
    {

    }

    double getRadius() const
    {
        return Sphere::getRadius();
    }

    double getArea() const
    {
        return getRadius() * getRadius() * 3.14;
    }
    void displayStatistics() const
    {
        cout << "Area of ball is " << getArea() << endl;
    }
};

int main()
{
    Sphere myShphere(3.0);
    Ball myBall(3.0);

    myShphere.displayStatistics();
    myBall.displayStatistics();

    Sphere* spherePtr = new Sphere(3.0);
    Ball* ballPtr = new Ball(3.0);

    spherePtr->displayStatistics();
    spherePtr = ballPtr;
    spherePtr->displayStatistics();
    ballPtr->displayStatistics();

    return 0;
}
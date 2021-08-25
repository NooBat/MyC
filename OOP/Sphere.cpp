#include "Sphere.h"

const double PI = 3.1416;

Sphere::Sphere() {
    setRadius(1.0);
}

Sphere::Sphere(double initialRadius) {
    if (initialRadius <= 0) setRadius(1.0);
    else setRadius(initialRadius);
}

void Sphere::setRadius(double newRadius) {
    if (newRadius <= 0) this->radius = 1.0;
    this->radius = newRadius;
}

double Sphere::getRadius() const {
    return radius;
}

double Sphere::getDiameter() const {
    return 2 * radius;
}

double Sphere::getCircumference() const {
    return getDiameter() * PI;
}

double Sphere::getArea() const {
    return radius * radius * PI;
}

double Sphere::getVolume() const {
    double sphereCubed = radius * radius * radius;
    return sphereCubed * 4 / 3.0 * PI;
}
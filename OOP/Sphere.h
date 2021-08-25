#ifndef Sphere_h
#define Sphere_h

class Sphere {
private:
    double radius;

public: 
    /** Default constructor: Creates a sphere and initializes
     * its radius to a default value.
     * @pre NONE.
     * @post A sphere of radius 1 exists. */
    Sphere();

    /** Constructor: Creates a sphere and initializes
     * its radius.
     * @pre initialRadius is the desired radius.
     * @post A sphere of radius initialRadius exists. */
    Sphere(double initialRadius);

    /** Sets (alters) radius of this sphere
     * @pre newRadius is the desired radius.
     * @post The sphere's radius is now newRadius. */
    void setRadius(double newRadius);

    /** Gets this sphere's radius
     * @pre NONE
     * @post returns the radius */
    double getRadius() const;

    /** Gets this sphere's diameter
     * @pre NONE
     * @post returns the diameter */
    double getDiameter() const;

    /** Gets this sphere's circumference
     * @pre NONE
     * @post returns the circumference */
    double getCircumference() const;

    /** Gets this sphere's area 
     * @pre NONE
     * @post returns the area */
    double getArea() const;

    /** Gets this sphere's volume
     * @pre NONE
     * @post returns the volume */
    double getVolume() const;
};
#include "Sphere.cpp"
#endif


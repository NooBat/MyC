#ifndef _RECTANGLE
#define _RECTANGLE

class Rectangle {
private:
    double length;     //length (should be equal or larger than width)
    double width;      

public:
    Rectangle();

    Rectangle(const double& length, const double& width);

    bool setLength(const double& newLength);

    bool setWidth(const double& newWidth);

    double getLength() const;

    double getWidth() const;

    double getPerimeter() const;

    double getArea() const;
};

Rectangle::Rectangle(): length(0.0), width(0.0) {

}

Rectangle::Rectangle(const double& length, const double& width) {
    setLength(length);
    setWidth(width);
}

bool Rectangle::setLength(const double& newLength) {
    if (newLength < this->width || newLength == 0) return false;

    length = newLength;
    return true;
}

bool Rectangle::setWidth(const double& newWidth) {
    if (newWidth > this->length || newWidth == 0) return false;

    width = newWidth;
    return true;
}

double Rectangle::getLength() const {
    return length;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getPerimeter() const {
    return 2 * (length + width);
}

double Rectangle::getArea() const {
    return length * width;
}
#endif
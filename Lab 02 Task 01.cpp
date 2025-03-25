#include <iostream>

using namespace std;

class Shape {
public:
    virtual double area() const = 0;

    // Virtual destructor (important for inheritance with pointers)
    virtual ~Shape() {}
};


class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        double pi = 3.14; // Using the value of pi as 3.14
        return pi * radius * radius;
    }

    double getRadius() const {
        return radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    
    Rectangle(double l, double w) : length(l), width(w) {}

  
    double area() const override {
        return length * width;
    }

    double getLength() const {
        return length;
    }

    double getWidth() const {
        return width;
    }
};

int main() {
    // Create a Circle object
    Circle myCircle(5.0);
    cout << "Circle with radius " << myCircle.getRadius() << " has area: " << myCircle.area() << endl;

    // Create a Rectangle object
    Rectangle myRectangle(4.0, 6.0);
    cout << "Rectangle with length " << myRectangle.getLength() << " and width " << myRectangle.getWidth() << " has area: " << myRectangle.area() << endl;

    return 0;
}
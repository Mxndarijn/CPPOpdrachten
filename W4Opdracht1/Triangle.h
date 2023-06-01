#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle();
    Triangle(double side1, double side2, double side3);
    double getSide1() const;
    double getSide2() const;
    double getSide3() const;
    double getArea() const;
    double getPerimeter() const;

private:
    double side1;
    double side2;
    double side3;
};

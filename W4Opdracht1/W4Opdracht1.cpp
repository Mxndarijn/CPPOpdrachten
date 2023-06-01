// W4Opdracht1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Triangle.h"

int main() {
    Triangle triangle1;
    Triangle triangle2(3.0, 4.0, 5.0);

    std::cout << "Triangle 1: " << std::endl;
    std::cout << "Side 1: " << triangle1.getSide1() << std::endl;
    std::cout << "Side 2: " << triangle1.getSide2() << std::endl;
    std::cout << "Side 3: " << triangle1.getSide3() << std::endl;
    std::cout << "Area: " << triangle1.getArea() << std::endl;
    std::cout << "Perimeter: " << triangle1.getPerimeter() << std::endl;

    std::cout << "\nTriangle 2: " << std::endl;
    std::cout << "Side 1: " << triangle2.getSide1() << std::endl;
    std::cout << "Side 2: " << triangle2.getSide2() << std::endl;
    std::cout << "Side 3: " << triangle2.getSide3() << std::endl;
    std::cout << "Area: " << triangle2.getArea() << std::endl;
    std::cout << "Perimeter: " << triangle2.getPerimeter() << std::endl;

    return 0;
}
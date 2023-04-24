// Opdracht1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "StopWatch.h"

int main()
{
    //Nummers aan een vector toevoegen. (geen list want vector
    std::vector<int> numbers(100000);
    for (int i = 0; i < 100000; i++) {
        numbers[i] = rand() % 100000;
    }

    //Stopwatch aanmaken, daarna sorteren
    StopWatch stopWatch;
    std::sort(numbers.begin(), numbers.end());
    stopWatch.stop();

    std::cout << "Elapsed Time: " << stopWatch.getElapsedTime() << " milliseconds";

}


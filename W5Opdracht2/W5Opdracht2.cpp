#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

typedef std::function<int(int, int)> MyTypeFunc;

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    // Lambda-functie die de getallen optelt
    MyTypeFunc sum = [](int total, int num) {
        return total + num;
    };

    // Gebruik van for_each om de lambda-functie op elk getal toe te passen
    int result = 0;
    std::for_each(numbers.begin(), numbers.end(), [&](int num) {
        result = sum(result, num);
        });

    // Resultaat weergeven
    std::cout << "Het totaal is: " << result << std::endl;

    return 0;
}
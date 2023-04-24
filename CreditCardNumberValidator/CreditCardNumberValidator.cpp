#include <iostream>
#include <string>

using namespace std;
bool isValid(string& cardNumber);
bool startsWith(const string& cardNumber, const string& substr);
int sumOfDoubleEvenPlace(const string& cardNumber);
int getDigit(int number);
int sumOfOddPlace(const string& cardNumber);

int main() {
    std::string cardNumber;
    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    cout << "Checking credit card number: " << cardNumber << endl;

    if (isValid(cardNumber)) {
        std::cout << "The card number is valid." << std::endl;
    }
    else {
        std::cout << "The card number is invalid." << std::endl;
    }

    return 0;
}

bool isValid(string& cardNumber) {
    if (cardNumber.length() < 13 || cardNumber.length() > 16) {
        cout << "Card number does not have a valid amount of digits." << endl;
        return false;
    }

    if (
        !startsWith(cardNumber, "4") &&
        !startsWith(cardNumber, "5") &&
        !startsWith(cardNumber, "37") &&
        !startsWith(cardNumber, "6")
        ) {
        cout << "Card number does not have a valid starting number." << endl;
        return false;
    }

    int sumOfDoubleEvenPlaces = sumOfDoubleEvenPlace(cardNumber);
    cout << "Sum of even: " << sumOfDoubleEvenPlaces << endl;

    int sumOfOddPlaces = sumOfOddPlace(cardNumber);
    cout << "Sum of odds: " << sumOfOddPlaces << endl;

    int sumTotal = sumOfOddPlaces + sumOfDoubleEvenPlaces;

    cout << "Total: " << sumTotal << endl;

    return (sumTotal % 10 == 0);




}

bool startsWith(const string& totalString, const string& subString) {
    return totalString.starts_with(subString);
}

int sumOfDoubleEvenPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.length() - 2; i >= 0; i -= 2) {
        int number = (cardNumber[i] - '0') * 2;
        sum += getDigit(number);
    }

    return sum;
}

int getDigit(int number) {
    if (number > 9) {
        return (number / 10) + (number % 10);
    }
    else {
        return number;
    }
}

int sumOfOddPlace(const string& cardNumber) {
    int sum = 0;
    for (int i = cardNumber.length() - 1; i >= 0; i -= 2) {
        sum += (cardNumber[i] - '0');
    }

    return sum;
}

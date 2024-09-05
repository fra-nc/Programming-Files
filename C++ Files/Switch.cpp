#include <iostream>

int main()
{
    char grade;
    std::cout << "Enter grade A to E: ";
    std::cin >> grade;

    switch (grade)
    {
    case 'A':
        std::cout << "Excellent.";
        break;
    case 'B':
        std::cout << "Very good.";
        break;
    case 'C':
        std::cout << "Good trial.";
        break;
    case 'D':
        std::cout << "Work harder.";
        break;
    case 'E':
        std::cout << "Fail.";
        break;

    default:
        std::cout << "Enter a valid input!";
        break;
    }
    return 0;
}
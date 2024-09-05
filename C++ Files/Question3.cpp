
#include <iostream>

int main() {
    int rows;

    // Input the number of rows
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    // First inverted full triangle
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i - 1; j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= 2 * (rows - i) + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // Second inverted full triangle
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    return 0;
}

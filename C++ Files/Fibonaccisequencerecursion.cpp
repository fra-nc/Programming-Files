#include<iostream>

//Function  using recursion to generate the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;

    std::cout << "Enter the number of terms in the Fibonacci sequence: ";
    std::cin >> n;//The number of terms is entered by the user

    std::cout << "Fibonacci Sequence:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacci(i) << ", ";//fibonacci sequence is generated
    }

    return 0;
}

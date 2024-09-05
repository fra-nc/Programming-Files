#include <iostream>

  // Function to calculate factorial using recursion
  unsigned long long calculateFactorial(int n) {
  // Base case: If n is 0, return 1
 if (n == 0) {
 return 1;
  } else {
 // Recursive case: Calculate factorial recursively
 return static_cast<unsigned long long>(n) * calculateFactorial(n - 1);
}
 }

 int main() {
 // Declare a variable to store the input number
 int n;

// Prompt the user to enter a non-negative integer
 std::cout << "Enter a non-negative integer to calculate its factorial: ";
 std::cin >> n;

 // Check if the input is valid (non-negative)
 if (n < 0) {
 // Display an error message for invalid input
 std::cout << "Invalid input. Please enter a non-negative integer." << std::endl;
 // Exit with an error code
return 1;
}

 // Calculate factorial using recursion
 unsigned long long result = calculateFactorial(n);

// Display the calculated factorial
 std::cout << "Factorial of " << n << " = " << result << std::endl;

 // Exit successfully
return 0;
 }

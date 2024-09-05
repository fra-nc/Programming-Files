#include <iostream>

// Function to calculate factorial using iteration

unsigned long long calculateFactorialiteration(int n)
{
    // Base case: If n is 0, return 1
    if (n == 0)
    {
        return 1;
    }
   unsigned long long factorial=1;

   for(int i=1; i<=n;++i){
    factorial=factorial*i;
   }
   return factorial;
}

int main()
{
    // Declare a variable to store the input number
    int n;

    // Prompt the user to enter a non-negative integer
    std::cout << "Enter a non-negative integer to calculate its factorial: ";
    std::cin >> n;

    // Check if the input is valid (non-negative)
    if (n < 0)
    {
        // Display an error message for invalid input
        std::cout << "Invalid input. Please enter a non-negative integer." << std::endl;
        // Exit with an error code
        return 1;
    }

    // Calculate factorial 
    unsigned long long result = calculateFactorialiteration(n);

    // Display the calculated factorial
    std::cout << "Factorial of " << n << " = " << result << std::endl;

    // Exit successfully
    return 0;
}
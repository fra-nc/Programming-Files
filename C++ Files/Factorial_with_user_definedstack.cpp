#include <iostream>
#include <stack>
using namespace std;

struct stack_define
{
    int n;
    unsigned long long result;
};

// Function to calculate factorial using user defined stack

unsigned long long factorial(int n)
{
    stack<stack_define> my_stack;

    my_stack.push({n, 1});
    int result = 1;

    while (my_stack.empty() == false)
    {
        stack_define current = my_stack.top();
        my_stack.pop();

        if (current.n == 0)
        {
            result = current.result;
        }
        else
        {
            my_stack.push({current.n - 1, current.n * current.result});
        }

    }
    return result;
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
  unsigned long long result = factorial(n);

  // Display the calculated factorial
  std::cout << "Factorial of " << n << " = " << result << std::endl;

  // Exit successfully
  return 0;
}
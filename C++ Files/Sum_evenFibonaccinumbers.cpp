#include <iostream>
using namespace std;

// Function to display and calculate the sum of either even or odd numbers in Fibonacci sequence
long long displayAndSumFibonacci(int n, bool sumEven)
{
    long long term1 = 0, term2 = 1, nextTerm = 0, sum = 0;

    // Check if the number of terms is valid
    if (n <= 0)
    {
        cout << "Please enter a positive integer.";
    }
    else if (n == 1)
    {
        cout << "Fibonacci Sequence:" << term1 << endl;
        sum = sumEven ? 0 : term1;  // Initialize sum
    }
    else
    {
        cout << "Fibonacci Sequence:" << term1 << ", " << term2;

        sum = sumEven ? (term2 % 2 == 0 ? term2 : 0) : term2;

        for (int i = 3; i <= n; ++i)
        {
            nextTerm = term1 + term2; 
            cout << ", " << nextTerm;

            if (sumEven && nextTerm % 2 == 0)
            {
                sum += nextTerm;
            }
            else if (!sumEven && nextTerm % 2 != 0)
            {
                sum += nextTerm;
            }

            term1 = term2;    // Update term1
            term2 = nextTerm; // Update term2
        }
    }

    cout << endl;
    return sum;
}

int main()
{
    int numberOfTerms;
    bool sumEven;

    cout << "Enter the number of terms:";
    cin >> numberOfTerms; // Input number of terms from user

    cout << "Do you want to calculate the sum of even numbers? (1 for Yes, 0 for No):";
    cin >> sumEven; // Input user choice (1 for sum of even, 0 for sum of odd)

    long long sum = displayAndSumFibonacci(numberOfTerms, sumEven);

    if (sumEven)
    {
        cout << "Sum of even numbers in Fibonacci sequence: " << sum << endl;
    }
    else
    {
        cout << "Sum of odd numbers in Fibonacci sequence: " << sum << endl;
    }

    return 0;
}

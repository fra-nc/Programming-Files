#include <iostream>
using namespace std;

// Function to display Fibonacci sequence
void displayFibonacci(int n)
{
    long long term1 = 0, term2 = 1, nextTerm = 0;

    // Check if the number of terms is valid
    if (n <= 0)
    {
        cout << "Please enter a positive integer.";
    }
    else if (n == 1)
    {
        cout << "Fibonacci Sequence:" << term1;
    }
    else
    {
        cout << "Fibonacci Sequence:" << term1 << ", " << term2;
        for (int i = 3; i <= n; ++i)
        {
            nextTerm = term1 + term2; // Calculate next term
            cout << ", " << nextTerm;
            term1 = term2;    // Update term1
            term2 = nextTerm; // Update term2
        }
    }
    cout << endl;
}
int main()
{
    int numberOfTerms;
    cout << "Enter the number of terms:";
    cin >> numberOfTerms; // Input number of terms from user

    displayFibonacci(numberOfTerms); // Function call

    return 0;
}
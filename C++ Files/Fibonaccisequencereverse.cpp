#include <iostream>
using namespace std;

// Function to display reverseFibonacci sequence
void reverseFibonacci(int n)
{
    long long term1 = 0, term2 = 1, nextTerm = 0;
    int reverseFibonacci[n];//Array to store n terms

    // Check if the number of terms is valid
    if (n <= 0)
    {
        cout << "Please enter a positive integer.";
    }
    else if (n == 1)
    {
        cout << "Fibonacci Sequence: 0";
    }
    else
    {
         //Declaring  and initializing arrays
         reverseFibonacci[0]={0};
         reverseFibonacci[1]={1};
 
        for (int i = 2; i < n; ++i)
        {
            nextTerm = term1 + term2; // Calculate next term
            reverseFibonacci[i]=nextTerm;
            term1 = term2;    // Update term1
            term2=nextTerm;   // Update term2
        }
        for (int i=n-1; i>=0; --i){
            cout<<reverseFibonacci[i]<<", ";
        }
        
    }
    cout << endl;
}
int main()
{
    int numberOfTerms;
    cout << "Enter the number of terms:";
    cin >> numberOfTerms; // Input number of terms from user

    reverseFibonacci(numberOfTerms); // Function call

    return 0;
}
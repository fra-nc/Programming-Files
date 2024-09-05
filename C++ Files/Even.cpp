#include<iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter a value ";
    cin>>n;

    if (n%2==0)
        cout << n << " is an even number" << endl;
    else
        cout << n << " is not an even number" << endl;
    return 0;
}

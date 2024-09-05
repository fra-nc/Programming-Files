#include <iostream>
#include <string>
#include <cctype>// for tolower and isalnum functions
#include <fstream>//to access file
using namespace std;
// Function to normalize the string
string normalize(const string& s)
{
    string result;
    for (char c : s)
//code to pe executed for each character im strimg s
    {
        if (isalnum(c))   // Check if character is alphanumeric
        {
            result += tolower(c); // Convert to lowercase and add to
//result
        }
    }
    return result;
}
// Function to check if a string is a palindrome
bool isPalindrome(const string& s)
{
    string str = normalize(s); // Normalize the input string
    int left = 0; // Starting index
    int right = str.length() - 1; // Ending index
    while (left < right)   // Iterate until pointers meet
    {
        if (str[left] != str[right])
        {
            return false; // Characters differ, not a palindrome
        }
        left++; // Move left pointer rightward
        right--; // Move right pointer leftward
    }
    return true; // String is a palindrome
}


void palifile(const string& filename)
{
    ifstream file(filename);//the class for handling input from a file
    if(file.is_open())
    {
        string line;
        while (getline(file,line))  // Read input string
        {
            if (isPalindrome(line))
            {
                cout << "\"" << line << "\" is a palindrome." << endl;
            }
            else
            {
                cout << "\"" << line << "\" is not a palindrome." << endl;
            }
        }
        file.close(); // Close the file when done
    }
    else
    {
        cerr<<"Unable to open file: " << filename << endl;
    }
}
int main()
{
    string filename;
    cout << "Enter a filename: ";
    cin>>filename;
    palifile(filename);
    return 0;
}

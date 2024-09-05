#include <iostream>
#include <cctype> // for tolower and isalnum functions
#include <cstring> // for strlen function
using namespace std;

// Function to normalize the string
void normalize(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; ++i) {
        str[i] = tolower(str[i]); // Convert to lowercase
    }
}

// Overloaded function to normalize the string
void normalize(string& str) {
    for (char& c : str) {
        c = tolower(c); // Convert to lowercase
    }
}

// Function to check if a string is a palindrome
bool isPalindrome(char* str) {
    int length = strlen(str);
    int left = 0; // Starting index
    int right = length - 1; // Ending index

    while (left < right) { // Iterate until pointers meet
        if (str[left] != str[right]) {
            return false; // Characters differ, not a palindrome
        }
        left++; // Move left pointer rightward
        right--; // Move right pointer leftward
    }
    return true; // String is a palindrome
}

// Overloaded function to check if a string is a palindrome
bool isPalindrome(const string& str) {
    string normalized = str;
    normalize(normalized);
    
    int length = normalized.length();
    int left = 0; // Starting index
    int right = length - 1; // Ending index

    while (left < right) { // Iterate until pointers meet
        if (normalized[left] != normalized[right]) {
            return false; // Characters differ, not a palindrome
        }
        left++; // Move left pointer rightward
        right--; // Move right pointer leftward
    }
    return true; // String is a palindrome
}

int main() {
    const int maximumStringLength = 125; // specifiy the length of string
    char inCharArray[maximumStringLength];
    string inputString;

    cout << "Enter a string: ";
    cin.getline(inCharArray, maximumStringLength); // Read input string as character array

    inputString = inCharArray; // Convert the character array to a string

    normalize(inCharArray);
    normalize(inputString);

    

    if (isPalindrome(inputString)) {
        cout << "\"" << inputString << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << inputString << "\" is not a palindrome." << endl;
    }

    return 0;
}
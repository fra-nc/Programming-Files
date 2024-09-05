#include <iostream>
#include <string>
#include <cctype> // for tolower and isalnum functions
using namespace std;
// Function to normalize the string
string normalize(const string& s) {
 string result;
 for (char c : s) {
 if (isalnum(c)) { // Check if character is alphanumeric
 result += tolower(c); // Convert to lowercase and add to result

 }
 }
 return result;
}
// Function to check if a string is a palindrome
bool isPalindrome(const string& s) {
 string str = normalize(s); // Normalize the input string
 int left = 0; // Starting index
 int right = str.length() - 1; // Ending index

 while (left < right) { // Iterate until pointers meet
 if (str[left] != str[right]) {
 return false; // Characters differ, not a palindrome
 }
 left++; // Move left pointer rightward
 right--; // Move right pointer leftward
 }
 return true; // String is a palindrome
}
// Main function
int main() {
 string input;
 cout << "Enter a string: ";
 getline(cin, input); // Read input string

 if (isPalindrome(input)) {
 cout << "\"" << input << "\" is a palindrome." << endl;
 } else {
 cout << "\"" << input << "\" is not a palindrome." << endl;
 }

 return 0;
}
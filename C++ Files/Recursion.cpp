#include<iostream>
//Recursive function to calculate sum of integers from 1 to k
int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

int main() {
    //Call the function with argument 10
  int result = sum(10);
  std::cout << result;
  return 0;
}
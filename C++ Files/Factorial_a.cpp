#include<iostream>

//Function to calculate and display factorial
void calculateFactorial(int n){
     //Initialize the factorial to 1
     unsigned long long factorial=n;

     //Loop to calculate the factorial
     for(int i=n-1; i>0; --i){
        factorial *=i;

     }
     //Display the calculated factorial
     std::cout<<"Factorial of "<<n<<" = "<<factorial<<std::endl;
}

int main(){
    //Declare a variable to store the input number
    int n;

    //Prompt the user to enter a non-negative integer
    std::cout<<"Enter a non-negative integer to calculate its factorial: ";

    //Input the value of n
    std::cin>>n;

    //Check if the input is valid
    if(n<0){
        //Display an error message for invalid input
        std::cout<<"Invalid input. Please enter a non-negative integer."<<std::endl;
        //Exit with an error code
        return 1;
    }

    std::cout<<std::endl;
    //Calculate and display the factorial
    calculateFactorial(n);

    //Exit successfully
    return 0;
}
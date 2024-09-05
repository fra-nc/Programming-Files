#include<iostream>

//Function to generate and display Fibonacii series
void generateFibonacci(int n){
    //Initialize variables to store current and next terms in the Fibonaccin series
    int a=0, b=1, nextTerm;
    double sum=0;
    double mean=sum/n;
    //Display information about the series
    std::cout<<"Fibonacci Series up  "<<n<<" terms: ";

    //Loop to generate and display Fibonacci series
    for(int i=1; i<=n; ++i){
        //Display the current term
        std::cout<<a;
        //Find the sum of the Fibonacci series
        sum += a;
      
        //Add a comma and space if not the last term
        if(i<n){
            std::cout<<", ";
        }

        //Update variables to generate the next term
        nextTerm=a+b;
        a=b;
        b=nextTerm;
    }

    //Move to the next line after displaying the series
    std::cout << std::endl;

    //Find mean 
    mean=sum/n;

    std::cout<<"The sum = "<<sum<<'\n';
    std::cout<<"The mean = "<<mean<<'\n';

}

int main(){
    //Declare variable to store the number of terms
    int n;

    //Prompt the user to enter the number of terms
    std::cout<<"Enter the number of terms for Fibonacci series: ";
    std::cin>>n;

    //Check if the input is valid
    if(n<=0){
        //Display an error message for invalid input
        std::cout<<"Invalid input. Please enter a positive integer."<<std::endl;
        //Exit with an error code
        return 1;
    }
    //Enter New line
    std::cout<<std::endl;
    //Generate and display Fibonacci series
    generateFibonacci(n);

    //Exit successfully
    return 0;
}
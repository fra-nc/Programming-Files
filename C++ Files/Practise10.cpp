#include<iostream>

int main()
{
    //prompt user to enter numbers
    double number1,number2,number3;
    std::cout<<"Enter three numbers:";
    std::cin>>number1>>number2>>number3;
    //compute average
    double average=(number1+number2+number3)/3;
    //display result
    std::cout<<"The average of "<<number1<<""<<number2<<""<<number3<<"is"<<average<<'\n';
    return 0;
}

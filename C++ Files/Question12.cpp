
#include<iostream>

int main()
{
    //declare variables
    double kilograms;
    double time;
    double average;
    //initialize variables
    kilograms=5.553;
    time=7770.0;
    //find average
    average=kilograms*3600/time;
    //display average
    std::cout<<"the average sales in kilograms per hour is "<<average<<'\n';
    return 0;
}

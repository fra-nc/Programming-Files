
#include<iostream>

int main(){
    //declare variables
    double grams;
    double time;
    double average;

    //initialize variables
    grams=6000.0;
    time=55830.0;

    //find the average
    average=grams*3600/time;

    //display average
    std::cout<<"The average sales in grams per hour is "<<average<<'\n';
    return 0;

}

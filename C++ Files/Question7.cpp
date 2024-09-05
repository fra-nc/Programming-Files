
#include<iostream>
#include<cmath>

int main()
{
    //declare variables
    double x;
    double y;
    double squareroot;
    double sqroot;
    //initialize variables
    x=6*(1.0+1.0/4+1.0/9+1.0/16+1.0/25);
    y=6*(1.0+1.0/4+1.0/9+1.0/16+1.0/25+1.0/36);
    //compute square root
    squareroot=sqrt(x);
    sqroot=sqrt(y);
    //display square root
    std::cout<<"the square root is"<<squareroot<<'\n';
    std::cout<<"the sq root is"<<sqroot<<'\n';
    return 0;


}

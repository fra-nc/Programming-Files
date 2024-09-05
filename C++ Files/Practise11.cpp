#include<iostream>

int main()
{
    //prompt user to enter radius of circle
    double radius;
    std::cout<<"Enter the radius of circle";
    std::cin>>radius;
    //compute area
    double area=radius*radius*22/7;
    //display area
    std::cout<<"the area is "<<area<<'\n';
    return 0;

}


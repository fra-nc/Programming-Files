
#include<iostream>

int main()
{
    //declare variables
    double side;
    double area;
    double perimeter;
    //initialize variables
    side=1.732;
    //calculate area and perimeter
     area=side*(side*side)/4;
     perimeter=3*side;
    //display area and perimeter
      std::cout<<"The area is"<<area<<'\n';
      std::cout<<"The perimeter is"<<perimeter<<'\n';

      return 0;


}

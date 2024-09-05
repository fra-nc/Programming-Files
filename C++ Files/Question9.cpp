
#include<iostream>

int main()
{
  //declare variables
  double side;
  double area;
  double perimeter;
  //initialize variables
  side=5.2;

  //Step 2:Compute area and perimeter
  area=side*side;
  perimeter=4*side;
  //Step 3: Display the area and perimeter

  std::cout<<"The area is"<<area<<'\n';
  std::cout<<"The perimeter is"<<perimeter<<'\n';
  return 0;

}

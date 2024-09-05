#include<iostream>

int main()
{
    //prompt user to enter year of birth
    double year;
    std::cout<<"Enter year of birth";
    std::cin>>year;
    //compute age
    double age=2023-year;
    //display age
    std::cout<<"the age is:"<<age<<'\n';
    return 0;
    
}

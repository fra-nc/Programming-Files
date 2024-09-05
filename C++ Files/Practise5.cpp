
#include<iostream>

int main()
{
    //declare variables
    int b;
    int d;
    int i;
    int birthsperyear;
    int deathsperyear;
    int immigrantsperyear;
    int population;
    int newpopulation;
    //initialize variables
    b=7;
    d=13;
    i=45;
    population=312032486;
    //compute
    birthsperyear=(365*24*60*60)/b;
    deathsperyear=(365*24*60*60)/d;
    immigrantsperyear=(365*24*60*60)/i;
    newpopulation=(population+birthsperyear+immigrantsperyear)-deathsperyear;
    //display new population
    std::cout<<"the new population after one year is "<<newpopulation<<'\n';
    return 0;

}

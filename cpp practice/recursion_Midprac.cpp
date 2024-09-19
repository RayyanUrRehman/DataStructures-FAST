#include<iostream>
using namespace std;

// Write a recursive function CountOnes that takes an unsigned integer and return the number of ones 
// in binary representation of that given number. For an example: if 28 is given as an argument to this 
// function it will return 3, as 28 is 11100.


int CountOnes(int num)
{   
     
    if (num==0) 
        return 0; 
    else if (num==1) 
        return 1; 
    else 
    { 
        return CountOnes(num/2)+ CountOnes(num%2); 
    } 
 


}


int main()
{
    cout<<CountOnes(28);
}
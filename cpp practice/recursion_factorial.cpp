#include<iostream>
using namespace std;


int factorial(int num)
{
    if (num == 1){
        return num;
    }
    num = num * factorial(num-1);
}


int main()
{
    int num = 6;
    cout<<num<<"! = "<<factorial(num);
    return 0;
}
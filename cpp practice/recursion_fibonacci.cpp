#include<iostream>
using namespace std;

// Write a recursive function to find the n-th Fibonacci number

int fibonacci(int num)
{
    if (num == 0){
        return 0;
    }
    else if (num == 1){
        return 1;
    }
    else{
        num = fibonacci(num-1) + fibonacci(num-2);
        return num;
    }

}



int main()
{
    cout<<fibonacci(6);
}
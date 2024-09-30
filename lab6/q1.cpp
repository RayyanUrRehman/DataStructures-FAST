#include<iostream>
using namespace std;

// Implement and insert the values “BORROWROB” in the stack and identify if it’s palindrome
// or not. Use the push and pop functions to accomplish this (Note: Use Arrays to accomplish
// this).

int maxsize = 10;
class Stack
{
    string arr[10];
    int top;

    public:
    Stack(){top = -1;}

    bool isFull()
    {
        if (top == maxsize-1){
            return true;
        }
        else{
            return false;
        }
    }

    void push(string data)
    {   
        if (isFull()){
            cout<<"Can not push. limit reached"<<endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    bool isEmpty()
    {
        if (top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    string pop()
    {
        string temp;
        if (isEmpty()){
            cout<<"Can not pop, stack empty."<<endl;
        }
        else{
            temp = arr[top];
            top--;
        }
        return temp;
    }


    void size()
    {
        cout<<top<<endl;
    }


    bool isPalindrome()
    {
        string upperHalf[4];
        string lowerHalf[4];
        int temp = top;

        int i=0;
        while(temp > 4){
            upperHalf[i] = pop();
            i++;
            temp--;
        }

        string middle = pop();
        temp--;
        i=0;
        while(temp > -1){
            lowerHalf[i] = pop();
            temp--;
            i++;
        }

        // for (int i=0;i<4;i++){
        //     cout<<upperHalf[i]<<" ";
        // }cout<<endl;
        // for (int i=0;i<4;i++){
        //     cout<<lowerHalf[i]<<" ";
        // }

        bool palindrome = true;
        int j=3;
        for (int i=0;i<4;i++){
            if (lowerHalf[i] != upperHalf[j]){
                palindrome = false;
                cout<<"The stack is NOT a palindrome!";
                return palindrome;
            }
            j--;
        }
        cout<<"The stack is a palindrome!";
    }

};



int main()
{
    Stack stack;

    // test for palindrome
    // stack.push("B");
    // stack.push("O");
    // stack.push("R");
    // stack.push("R");
    // stack.push("O");
    // stack.push("R");
    // stack.push("R");
    // stack.push("O");
    // stack.push("B");


    // test for not a palindrome (original question)
    stack.push("B");
    stack.push("O");
    stack.push("R");
    stack.push("R");
    stack.push("O");
    stack.push("W");
    stack.push("R");
    stack.push("O");
    stack.push("B");


    stack.isPalindrome();

    return 0;
}
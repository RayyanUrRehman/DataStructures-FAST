#include<iostream>
using namespace std;

class bankAccount{
    public:
    int balance=0;

    bankAccount(){};
    bankAccount(int bal){
        balance = bal;
    }
    void print(){
        cout<<"Bank balance is: "<<balance<<endl;
    }
};


int main()
{   
    //a
    bankAccount account1;
    account1.print();

    //b
    bankAccount account2(1000);
    account2.print();

    //c
    bankAccount account3 = account2;
    account3.balance = account3.balance - 200;
    account3.print();
    account2.print();

    return 0;
}
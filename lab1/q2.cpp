#include <iostream>
using namespace std;

class Exam{
    private:
    string name;
    string date;
    int score;

    public:
    Exam(){};
    Exam(string n, string d,int s):name(n),date(d),score(s){};
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Score: "<<score<<endl;
    }
};


int main()
{
    Exam exam1("rayyan","20/08/24",99);
    Exam exam2 = exam1;
    exam1.display();
    exam2.display();
    //shallow copy done.
    //issue: if any pointer used, it does not copy the data of the pointer, hence mempory leaking and improper/incomplete copy of class.

    return 0;
}
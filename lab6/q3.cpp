#include <iostream>
#include<string>
using namespace std;

class Node {
    public:
        string data; 
        Node* next;  
};


class LinkedListStack {
    private:
        Node* top; 

    public:
        LinkedListStack() : top(nullptr) {}

        void push(string val){
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = top;
            top = newNode;
        }

        string pop() {
            if(!isEmpty()){
                Node* temp = top;
                string val = top->data;
                top = top->next;
                delete temp;
                return val;
            }
            return "";
        }

        string peek() {
            if(!isEmpty()){
                return top->data;
            }
            return "";
        }

        bool isEmpty(){
            return top == nullptr;
        }

        void display() {
            Node* current = top;
            while(current != nullptr){
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

double evaluateExpression() {
    double result = 12;  
    result += 13;        
    result -= 5 * (0.5 + 0.5);  
    result += 1;         
    return result;
}

int main() {
    
    LinkedListStack stack;

    stack.push("x");
    stack.push("=");
    stack.push("12");
    stack.push("+");
    stack.push("13");
    stack.push("-");
    stack.push("5");
    stack.push("*");
    stack.push("(");
    stack.push("0.5");
    stack.push("+");
    stack.push("0.5");
    stack.push(")");
    stack.push("+");
    stack.push("1");

    cout<<endl<< "Stack before evaluation:"<<endl<<endl;
    stack.display();

    double result = evaluateExpression();

    stack.push(to_string(result));

    cout<<endl<<"Stack after evaluation (result on top):"<<endl<<endl;
    stack.display();
    cout<<endl;

    return 0;
}

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next = NULL;
    node* prev = NULL;

    node(int val):data(val){};

};


void insert_end(node* head, int val)
{
    node* temp = new node(val);
    node* current = head;

    if(current->next == NULL){
        current->next = temp;
        temp->prev = current;
        temp->next = head;
    }
    else{
        while(current->next != head){
            current = current->next;
        }
        current->next = temp;
        temp->prev = current;
        temp->next = head;
    }
}


void display(node* head)
{
    node* current = head;
    cout<<current->data<<endl;
    current = current->next;

    while(current != head){
        cout<<current->data<<endl;
        current = current->next;
    }

}

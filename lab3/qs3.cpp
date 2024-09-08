#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int val):data(val),next(NULL){};
};

void insert_start(node* &head, int data)
{
    node* current = head;
    node* temp = new node(data);

    temp->next = head;
    head = temp;

    while(current->next != head){
        current = current->next;
    }
    current->next = head;

}

void insert_end(node* &head, int data)
{
    node* current = head;
    node* temp = new node(data);

    while(current->next != head){
        current = current->next;
    }

    current->next = temp;
    temp->next = head;
}

void insert_at_position(node* &head, int index, int data)
{
    node* current = head;
    node* temp = new node(data);
    int count=0;

    if (index == 0){
        insert_start(head,data);
    }
    else{
        while(count < index){
            current = current->next;
            count++;
        }
        temp->next = current->next;
        current->next = temp;
    }
}

void display(node* head)
{
    node* current = head;
    while(current->next != head){
        cout<<current->data<<endl;
        current = current->next;
    }
}

int main()
{
    node* node1 = new node(10);
    node* head = node1;


    return 0;
}
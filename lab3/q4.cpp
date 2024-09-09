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


void insert_start(node* &head, int data)
{
    node* temp = new node(data);
    node* current = head;

    while(current->next != head){
        current = current->next;
    }

    temp->next = head;
    temp->prev = current;
    head = temp;
    current->next = head;

}


void insert_at_position(node* &head, int index, int data)
{
    node* current = head;
    node* temp = new node(data);
    int count=1;

    if (index == 0){
        insert_start(head,data);
    }
    else{
        while(count < index){
            current = current->next;
            count++;
        }
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
        temp->prev = current;
        
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


void delete_node(node* head, int index)
{
    node* current = head;
    node* temp = NULL;
    int counter = 0;

    while(counter != index){
        temp = current;
        current = current->next;
        counter++;
    }

    temp->next = current->next;
    current->next->prev = temp;
    delete current;

}


int main()
{
    node* node1 = new node(10);
    node* head = node1;

    insert_end(head,20);
    insert_end(head,30);
    insert_end(head,40);

    insert_start(head,5);

    insert_at_position(head,3,25);
    display(head);

    cout<<endl;

    delete_node(head,3);
    display(head);
    return 0;

    // can check all functions one by one by uncommenting

}
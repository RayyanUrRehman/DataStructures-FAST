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


void insert(node* &head, int data)
{   
    node* newnode = new node(data);
    node* current = head;
    while(current != NULL && current->next != nullptr){
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
}


void display(node* &head)
{   
    node* current = head;
    while (current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}


void merge(node* &Lhead, node* &Mhead)
{
    node* current = Lhead;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = Mhead;
}


int main()
{
    // creating LL 'L'
    node* node1 = new node(10);
    node* Lhead = node1;
    insert(Lhead,20);
    insert(Lhead,30);
    insert(Lhead,40);


    // creating LL 'M'
    node* node2 = new node(50);
    node* Mhead = node2;
    insert(Mhead,60);
    insert(Mhead,70);
    insert(Mhead,80);

    cout<<"Linked List L:"<<endl;
    display(Lhead);

    cout<<endl;

    cout<<"Linked List M:"<<endl;
    display(Mhead);

    cout<<endl;

    merge(Lhead,Mhead);

    cout<<"Merged Link lists:"<<endl;
    display(Lhead);



    return 0;
}
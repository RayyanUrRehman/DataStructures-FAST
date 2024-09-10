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


void swap(node* &head, int val1, int val2)
{
    node* current = head;
    node* temp1 = NULL;
    node* temp2 = NULL;
    node* temp3 = NULL;

    int count = 0;
    while(current->next != head){
        if(count == val1){
            temp1 = current;
        }
        if(count == val2){
            temp2 = current;
        }
        current = current->next;
        count++;
    }

    // Swap next pointers
    temp3 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = temp3;

    // Swap prev pointers
    temp3 = temp1->prev;
    temp1->prev = temp2->prev;
    temp2->prev = temp3;

    
    if (temp1->next != nullptr) temp1->next->prev = temp1;
    if (temp2->next != nullptr) temp2->next->prev = temp2;
    if (temp1->prev != nullptr) temp1->prev->next = temp1;
    if (temp2->prev != nullptr) temp2->prev->next = temp2;

    
}


int main()
{
    node* node1 = new node(1);
    node* head = node1;

    insert_end(head,7);
    insert_end(head,4);
    insert_end(head,2);
    insert_end(head,6);
    insert_end(head,4);
    insert_end(head,5);
    insert_end(head,3);
    insert_end(head,9);
    insert_end(head,8);

    int num1,num2;
    cout<<"Enter two nodes keys: ";
    cin>>num1>>num2;
    cout<<"Initial linked list = ";
    display(head);
    cout<<endl;
    cout<<"After swapping = ";
    swap(head,num1,num2);
    display(head);



    return 0;
}

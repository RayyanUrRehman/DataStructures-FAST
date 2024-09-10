#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* next = NULL;
    node* prev = NULL;

    node(int data){
        this->data = data;
    }
};


void add_at_end(node* &head, int data)
{   
    node* newnode = new node(data);
    node* current = head;
    while(current != NULL && current->next != nullptr){
        current = current->next;
    }
    current->next = newnode;
    newnode->prev = current;
}


void displayLL(node* &head)
{   
    node* current = head;
    while (current!=NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
}


void delete_index(node* &head,int index)
{
    node* current = head;

    int count = 0;
    while (current != nullptr && count < index) {
        current = current->next;
        count++;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }

    // Update the prev pointer of the next node
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    // Free the memory of the node to be deleted
    delete current;

}

void alternatives(node* head, node* &alt_head)
{
    node* current = head;
    int alt = 0;

    node* alt_current = alt_head;

    while(current != NULL){
        if (alt % 2 != 0 && alt != 1){
            add_at_end(alt_head,current->data);
        }

        current = current->next;
        alt++;
    }

    current = head;
    alt = 0;

    //deleting odd indexes..
    while (current != nullptr){
        node* next_node = current->next;  

        if (alt % 2 != 0){
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            delete current;  
        }

        current = next_node;  
        alt++;  
    }
    
}


void reversing(node* &alt_head)
{
    node* current = alt_head;
    node* temp = NULL;

    while (current != nullptr) {
        temp = current->prev;       //swapping
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != nullptr) {
        alt_head = temp->prev;
    }
}


void append(node* &head, node* &alt_head)
{
    node* current = head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = alt_head;
}


int main()
{
    int val,num;
    cout<<"Enter number of nodes: ";
    cin>>num;

    cout<<"Enter node 1: ";
    cin>>val;

    node* node1 = new node(val);
    node* head = node1;

    for (int i=1;i<num;i++){
        cout<<"Enter node "<<i+1<<" :";
        cin>>val;
        add_at_end(head,val);
    }

    cout<<"Linked list = ";
    displayLL(head);
    cout<<endl;

    node* alt_node = new node(head->next->data);
    node* alt_head = alt_node;

    //alternating, reversing the alt LL, and appending it back, using 3 seperate functions.
    alternatives(head,alt_head);
    reversing(alt_head);
    append(head, alt_head);


    cout<<"Final Linked List: ";
    displayLL(head);

    return 0;
}
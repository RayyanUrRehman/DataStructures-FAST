#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* right;
    node* left; 

    node(int d){
        data = d;
        right = NULL;
        left = NULL;
    }
};

void print(node* root) {


    if (root == NULL) {
        return;
    }

    print(root->left);
    cout << root->data << " ";
    print(root->right);

}


bool search(node* root, int target)
{
    if (root->data == target){
        cout<<"Target found"<<endl;
        return true;
    }

    if (target < root->data){
        search(root->left, target);
    }
    else{
        search(root->right, target);
    }
    
}


node* insertInBST(node* &root, int data)
{
    if (root == NULL){
        root = new node(data);
        return root;
    }

    if (data > root->data){
        root->right = insertInBST(root->right, data);
    }
    else{
        root->left = insertInBST(root->left, data);
    }
    return root;
}


void takeInput(node* &root)  
{
    cout<<"Enter elements to insert in BST: ";
    int data;
    cin >> data;

    while(data != -1){
        insertInBST(root, data);
        cin>>data;
    }
}


int main()
{
    node* root = NULL;

    takeInput(root);
    cout<<"Printing: "<<endl;
    print(root);
    
    cout<<endl<<"Enter value to search in BST:";
    int target;
    cin>>target;
    search(root, target);

    return 0;
}
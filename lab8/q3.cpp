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


node* print(node* root)
{   
    if (root == NULL){
        return root;
    }
    else{
        root->left = print(root->left);
        cout<<root->data<<" ";
        root->right = print(root->right);
    }
}

node* insertInBST(node* &root, int data)
{
    if (root == NULL){
        root = new node(data);
        return root;
    }

    if(data < root->data){
        root->left = insertInBST(root->left, data);
        return root;
    }
    else{
        root->right = insertInBST(root->right, data);
        return root;
    }
}

bool search(node* &root, int target)
{
    if (root == NULL){
        cout<<"Target not found. Inserting target at right place"<<endl;
        root = insertInBST(root, target);
        return false;
    }
    if (root->data == target){
        cout<<"Target found."<<endl;
        return true;
    }

    if(target < root->data){
        search(root->left, target);
    }
    else{
        search(root->right, target);
    }
}


void takeInput(node* &root)
{
    int data;
    cout<<"Enter data: ";
    cin>>data;

    while(data != -1){
        root = insertInBST(root,data);
        cin>>data;
    }
}


int main()
{
    node* root = NULL;
    takeInput(root);
    cout<<"Printing BST in inorder: "<<endl;
    print(root);

    int target;
    cout<<"Enter value to find: ";
    cin>>target;
    search(root, target);
    cout<<endl;
    print(root);
    return 0;
}
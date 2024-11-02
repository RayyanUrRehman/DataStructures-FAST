#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* right;
    node* left;

    node(int d)
    {
        left = NULL;
        right = NULL;
        data = d;
    }
};


node* print(node* root)     //inorder 
{
    if (root == NULL){
        return root;
    }

    root->left = print(root->left);
    cout<<root->data<<" ";
    root->right = print(root->right);
}

node* insertInBST(node* &root, int val)
{
    if (root == NULL){
        root = new node(val);
        return root;
    }

    if (val > root->data){
        root->right = insertInBST(root->right, val);
    }
    else{
        root->left = insertInBST(root->left, val);
    }
    return root;
}


void takeInput(node* &root)
{
    int val;
    cout<<"Enter data: ";
    cin>>val;

    while(val != -1){
        root = insertInBST(root, val);
        cin>>val;
    }
}

int main()
{
    node* root = NULL;
    takeInput(root);
    print(root);
}
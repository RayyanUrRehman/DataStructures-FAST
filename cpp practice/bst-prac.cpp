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


node* print(node* root)     
{
    //inorder 
    if (root == NULL){
        return root;
    }

    root->left = print(root->left);
    cout<<root->data<<" ";
    root->right = print(root->right);
}


bool search(node* root, int target)
{
    if (root == NULL){
        cout<<"Target not found."<<endl;
        return false;
    }

    if(root->data == target){
        cout<<"Target found."<<endl;
        return true;
    }
    
    if(target > root->data){
        return search(root->right, target);
    }
    else{
        return search(root->left, target);
    }
}

node* minVal(node* root)
{       
    if (root == NULL){
        return root;
    }
    else{
        root = minVal(root->left);
    }
}

node* Delete(node* &root, int target)
{
    if(root == NULL){
        return root;
    }

    if (target == root->data){
        // 0 child
        if (root->right == NULL && root->left == NULL){
            delete root;
            return NULL;
        }

        //1 child
        //right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if(root->right != NULL && root->left != NULL){      
            //going via right subtree
            int min = minVal(root->right)->data;
            root->data = min;
            root->right = Delete(root->right, min);
            return root;
        }
    }

    if (target > root->data){
        root->right = Delete(root->right, target);
        return root;
    }
    else{
        root->left = Delete(root->left, target);
        return root;
    }
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
    cout<<endl;
    // search(root,5);
    Delete(root,6);
    cout<<endl;
    print(root);

}
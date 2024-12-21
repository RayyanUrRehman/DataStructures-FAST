#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    int height;
    node* left;
    node* right;

    node(int d){
        data = d;
        height = 0;
        left = nullptr;
        right = nullptr;
    }

};

int getHeight(node* root)
{
    return root->height;
}

int getBalance(node* root)
{
    return (getHeight(root->left) - getHeight(root->right));
}

node* rightRotate(node* root)
{
    node* leftChild = root->left;
    node* LRchild = leftChild->right;

    leftChild->right = root;
    root->left = LRchild;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return root;
}

node* leftRotate(node* root)
{
    node* rightChild = root->right;
    node* RLchild = rightChild->left;

    rightChild->left = root;
    root->right = RLchild;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    rightChild->height = max(getHeight(rightChild->left), getHeight(rightChild->right)) + 1;

    return root;
}

node* balanceNode(node* root)
{
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) > 0){
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) < 0){
        return leftRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < 1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


int main()
{
    return 0;
}
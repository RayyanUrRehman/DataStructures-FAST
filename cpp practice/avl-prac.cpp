#include<iostream>
using namespace std;

class Node
{
    public:
    Node* right;
    Node* left;
    int data;
    int height;

    Node(int val):right(NULL),left(NULL),data(val),height(1){};

};

int getHeight(Node* node)
{
    if (node == NULL){
        return 0;
    }
    return node->height;
}


int getBalance(Node* node)
{
    if (node == NULL){
        return 0;
    }
    return (getHeight(node->left) - getHeight(node->right));
}


Node* rotateRight(Node* root)
{
    Node* leftChild = root->left;
    Node* leftRightChild = leftChild->right;

    //rotate
    leftChild->right = root;
    root->left = leftRightChild;

    //balancing
    

}


int main()
{
    Node* node = new Node(10);
    return 0;
}
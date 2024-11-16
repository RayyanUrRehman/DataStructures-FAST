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

    //update heights
    leftChild->height = max(getHeight(leftChild->right), getHeight(leftChild->left)) + 1;
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    //return new root
    return leftChild;
}


Node* rotateLeft(Node* root)
{
    Node* rightChild = root->right;
    Node* rightLeftChild = rightChild->left;

    //rotate
    rightChild->left = root;
    root->right = rightLeftChild;

    //update height
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    rightChild->height = max(getHeight(rightChild->right), getHeight(rightChild->left)) + 1;

    //return new node
    return rightChild;
}

Node* balanceNode(Node* node)
{
    int balance = getBalance(node);

    //left-left imbalance
    if (balance > 1 && getBalance(node->left) >= 0){
        return rotateRight(node);
    }

    //right-right imbalance
    if (balance < -1 && getBalance(node->right) <= 0){
        return rotateLeft(node);
    }

    //right-Left imbalance
    if (balance < -1 && getBalance(node->right) > 0){
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    //left-right imbalance
    if (balance > 1 && getBalance(node->left) < 0){
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    //if no balance needed
    return node;
}


Node* insert(Node* root, int key)
{   
    if (root == NULL){
        return root = new Node(key);
    }

    if (key > root->data){
        root->right = insert(root->right, key);
    }
    else{
        root->left = insert(root->left, key);
    }

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    balanceNode(root);
    return root;
}

Node* minVal(Node* root)
{
    Node* current = root;
    while(current != nullptr){
        current = current->left;
    }
    return current;
}


Node* deletion(Node* root, int key)
{   
    if (root == nullptr){
        return root;
    }
    else if(key > root->data){
        root->right = deletion(root->right,key);
    }
    else if(key < root->data){
        root->left = deletion(root->left,key);
    }
    else{
        //0 child
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return nullptr;
        }
        
        //1 child
        if (root->right != nullptr && root->left == nullptr){
            Node* temp = root;
            delete root;
            return temp->right;
        }
        if (root->left != nullptr && root->right == nullptr){
            Node* temp = root;
            delete root;
            return temp->left;
        }

        // 2child
        if (root->left && root->right){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletion(root->right, mini);
            return root;
        }
    }

    //adjust root height
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    balanceNode(root);
    return root;
}

int main()
{
    Node* node = new Node(10);
    return 0;
}
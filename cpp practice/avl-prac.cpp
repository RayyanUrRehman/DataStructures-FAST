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

node* insert(int v, node* root)
{
    node* newNode = new node(v);
    if (root == nullptr){
        root = newNode;
        return root;
    }
    else if (root->data > v){
        root->left = insert(v,root->left);
    }
    else if(root->data < v){
        root->right = insert(v, root->right);
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    root = balanceNode(root);
    return root;
}

node* deleteNode(int v, node* root)
{
    if (root = nullptr){
        return root;
    }
    else if(root->data > v){
        root->left = deleteNode(v,root->left);
    }
    else if(root->data < v){
        root->right = deleteNode(v,root->right);
    }
    else{
        //0 child
        if (!root->left && !root->right){
            delete root;
            return nullptr;
        }
        
        //1child
        if (!root->left && root->right){
            node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right && root->left){
            node* temp = root->left;
            delete root;
            return temp;
        }

        //2child
        if (root->right && root->left){
            int mini = minNode(root->right)->data;
            root->data = mini;
            root->right = deleteNode(mini, root->right);
            return root;
        }
    }

    if (root== nullptr){
        return root;
    }

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    return balanceNode(root);

}

node* minNode(node* root)
{
    while(root != nullptr){
        root = root->left;
    }
    return root;
}


int main()
{
    return 0;
}
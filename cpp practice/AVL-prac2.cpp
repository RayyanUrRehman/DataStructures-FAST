#include<iostream>
using namespace std;

class node 
{
    public:
    int val;
    node* right;
    node* left;
    int height;

    node(int v){
        val = v;
        right = nullptr;
        left = nullptr;
        height = 0;
    }

    node(){
        left = nullptr;
        right = nullptr;
    }
};

int getHeight(node* node)
{
    if(node == nullptr){
        return -1;
    }
    return node->height;
}

int getBalance(node* node)
{
    int balance = getHeight(node->left) - getHeight(node->right);
    return balance;
}

node* rightRotate(node* root)
{
    node* leftChild = root->left;
    node* leftRight = leftChild->right;

    leftChild->right = root;
    root->left = leftRight;

    root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return leftChild;
}

node* leftRotate(node* root){
    node* rightChild = root->right;
    node* rightLeft = rightChild->left;

    rightChild->left = root;
    root->right = rightLeft;

    rightChild->height = max(getHeight(rightChild->right), getHeight(rightChild->left)) + 1;
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;

    return rightChild;
}

node* balanceNode(node* root)
{
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0){
       return rightRotate(root);
    }

    // RR
    if (balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }

    // LR
    if (balance > 1 && getBalance(root->left) <= 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (balance < -1 && getBalance(root->right) >= 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

node* insert(node* root, int val)
{
    node* newNode = new node(val);
    if(root == nullptr){
        root = newNode;
        return root;
    }
    else if(val < root->val){
        root->left = insert(root->left,val);
    }
    else if(val > root->val){
        root->right = insert(root->right, val);
    }

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    return balanceNode(root);
}

void preorder(node* root)
{
    if(root != nullptr){
        cout<<root->val<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}


node* minNode(node* root)
{
    node* current = root;
    while(current->left != nullptr){
        current = current->left;
    }
    return current;
}


node* deleteNode(node* root, int val)
{
    if (root == nullptr){
        return root;
    }
    else if (val < root->val){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->val){
        root->right = deleteNode(root->right, val);
    }
    else{
            //now we have reached the target node

        // 0 child
        if (!root->left && !root->right){
            delete root;
            return nullptr;
        }

        // 1 child
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

        // 2 child
        if (root->left && root->right){
            int mini = minNode(root->right)->val;
            root->val = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }

    if (root== nullptr){
        return root;
    }

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    return balanceNode(root);
}



int main()
{
    node* root = nullptr;


    // Inserting nodes to trigger all cases
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30); // Right-Right (Zig-Zig) case
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25); // Right-Left (Zig-Zag) case


    preorder(root);

    cout<<endl<<"After deletion: "<<endl;
    root = deleteNode(root, 25);
    preorder(root);
    return 0;
}
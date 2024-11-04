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
    if (root == NULL){
        cout<<"Target not found"<<endl;
        return false;
    }  
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

node* maxVal(node* root)
{
    if (root->right == NULL){
        cout<<"Largest element is: "<<root->data<<endl;
        return root;
    }
    else{
        root = maxVal(root->right);
    }
}

node* minVal(node* root)
{
    if (root->left == NULL){
        cout<<"Smallest element is: "<<root->data<<endl;
        return root;
    }
    else{
        root = minVal(root->left);
    }
}


node* Delete(node* root, int data)
{
    if (root == NULL){
        return root;
    }
    
    if (root->data == data){
        //0 child
        if (root->right==NULL && root->left==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //for left child
        if (root->right==NULL && root->left!=NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        //for right child
        if (root->left==NULL && root->right!=NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        //2child
        if (root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = Delete(root->right, mini);
            return root;
        }

    }
    else if(data < root->data){
        root->left =  Delete(root->left, data);
        return root;
    }
    else{
        root->right =  Delete(root->right, data);
        return root;
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
    
    // cout<<endl<<"Enter value to search in BST:";
    // int target;
    // cin>>target;
    // search(root, target);
    // cout<<endl;
    // cout<<endl;
    // maxVal(root);
    // minVal(root);

    cout<<endl<<"Enter value to delete: ";
    int num; cin>>num;
    Delete(root,num);
    print(root);

    return 0;
}
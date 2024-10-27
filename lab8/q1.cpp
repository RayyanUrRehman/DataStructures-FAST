#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* right;
    node* left;

    node(int d) {
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

node* insertInBST(node* &root, int data) {
    if (root == NULL) {
        root = new node(data);
        return root;
    }
    if (data > root->data) {
        root->right = insertInBST(root->right, data);
    } else {
        root->left = insertInBST(root->left, data);
    }
    return root;
}

void createBSTFromArray(node* &root, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insertInBST(root, arr[i]);
    }
}

int main() {
    node* root = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    createBSTFromArray(root, arr, n);

    cout << "In-order traversal: ";
    print(root);
    cout << endl;

    return 0;
}

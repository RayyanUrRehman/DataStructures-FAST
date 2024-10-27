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

int countNodes(node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


bool isCompleteBinaryTree(node* root, int index, int nodeCount) {
    if (root == NULL) return true;

    if (index >= nodeCount) return false;


    return isCompleteBinaryTree(root->left, 2 * index + 1, nodeCount) &&
           isCompleteBinaryTree(root->right, 2 * index + 2, nodeCount);
}

node* adjustTreeToCompleteAndFull(node* root) {
    if (root == NULL) return NULL;

    if ((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
        node* temp = (root->left != NULL) ? root->left : root->right;
        delete root;
        return temp; 
    }

    root->left = adjustTreeToCompleteAndFull(root->left);
    root->right = adjustTreeToCompleteAndFull(root->right);
    return root;
}

void createBSTFromArray(node* &root, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        insertInBST(root, arr[i]);
    }
}

int main() {
    node* root = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    createBSTFromArray(root, arr, n);

    cout << "In-order traversal of the BST after insertions: ";
    print(root);
    cout << endl;

    int nodeCount = countNodes(root);

    if (isCompleteBinaryTree(root, 0, nodeCount)) {
        cout << "The tree is a complete binary tree." << endl;
    } else {
        cout << "The tree is not a complete binary tree." << endl;
        root = adjustTreeToCompleteAndFull(root);

        cout << "After adjustment for the complete and full BST: ";
        print(root);
        cout << endl;
    }

    return 0;
}

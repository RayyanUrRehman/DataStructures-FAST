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


bool searchAndInsert(node* &root, int target, int &level, string &position, int currentLevel = 0) {
    if (root == NULL) {
        
        root = new node(target);
        level = currentLevel;
        position = "Inserted as " + string(currentLevel == 0 ? "root" : "child");
        return false; 
    }
    
    if (root->data == target) {
        level = currentLevel;
        position = "Found at " + string(currentLevel == 0 ? "root" : currentLevel % 2 == 0 ? "right child" : "left child");
        return true; 
    }
    
    if (target < root->data) {
        return searchAndInsert(root->left, target, level, position, currentLevel + 1);
    } else {
        return searchAndInsert(root->right, target, level, position, currentLevel + 1);
    }
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

    
    cout << "Enter value to search in the BST: ";
    int target;
    cin >> target;

    int level = -1;
    string position;
    bool found = searchAndInsert(root, target, level, position);

    if (found) {
        cout << "Value " << target << " " << position << " at level " << level << "." << endl;
    } else {
        cout << "Value " << target << " not found. " << position << " at level " << level << "." << endl;
    }

    return 0;
}

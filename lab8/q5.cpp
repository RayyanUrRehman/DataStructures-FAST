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

void insertInBST(node* &root, int data) {
    if (root == NULL) {
        root = new node(data);
        return;
    }
    if (data > root->data) {
        insertInBST(root->right, data);
    } else {
        insertInBST(root->left, data);
    }
}

void inOrderTraversal(node* root, int arr[], int &index) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left, arr, index);
    arr[index++] = root->data;  
    inOrderTraversal(root->right, arr, index);
}

void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int &mergedIndex) {
    int i = 0, j = 0;
    
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[mergedIndex++] = arr1[i++];
        } else {
            merged[mergedIndex++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[mergedIndex++] = arr1[i++];
    }

    while (j < size2) {
        merged[mergedIndex++] = arr2[j++];
    }
}

node* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    node* root = new node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void printInOrder(node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main() {
    node* root1 = NULL;
    int arr1[] = {5, 6, 3, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < n1; i++) {
        insertInBST(root1, arr1[i]);
    }

    node* root2 = NULL;
    int arr2[] = {2, 3, 1, 7, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < n2; i++) {
        insertInBST(root2, arr2[i]);
    }

    
    int inOrder1[10]; 
    int inOrder2[10]; 
    int index1 = 0, index2 = 0;

    inOrderTraversal(root1, inOrder1, index1);
    inOrderTraversal(root2, inOrder2, index2);

    
    int merged[20]; 
    int mergedIndex = 0;
    mergeSortedArrays(inOrder1, index1, inOrder2, index2, merged, mergedIndex);

    node* mergedRoot = sortedArrayToBST(merged, 0, mergedIndex - 1);

    cout << "Merged BST in sorted order: ";
    printInOrder(mergedRoot);
    cout << endl;

    return 0;
}

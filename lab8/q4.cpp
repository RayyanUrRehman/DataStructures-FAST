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

int findClosest(node* root, int x, int* closestValues, int& count) {
    if (root == NULL) return count;

    if (root->data == x) {
        closestValues[count++] = root->data;
    }

    if (x < root->data) {
        findClosest(root->left, x, closestValues, count);
    } else {
        findClosest(root->right, x, closestValues, count);
    }

    return count;
}

int main() {
    node* root = NULL;
    int arr[] = {10, 5, 11, 4, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    createBSTFromArray(root, arr, n);

    cout << "In-order traversal: ";
    print(root);
    cout << endl;

    int x;
    char choice;
    cout << "Enter a value X: ";
    cin >> x;

    cout << "Do you want to ceil or floor? (c/f): ";
    cin >> choice;

    if (choice == 'c') {
        x += 1; 
    } else if (choice == 'f') {
        x -= 1; 
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    int closestValues[10]; 
    int count = 0;
    findClosest(root, x, closestValues, count);

    if (count > 0) {
        cout << "Closest value(s) to " << x << ": ";
        for (int i = 0; i < count; ++i) {
            cout << closestValues[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No closest value found for " << x << endl;
    }

    return 0;
}

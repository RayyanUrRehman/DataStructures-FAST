#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int getHeight(Node* n) {
    return n ? n->height : 0;
}

int getBal(Node* n) {
    return n ? getHeight(n->left) - getHeight(n->right) : 0;
}

Node* rotRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Node* rotLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int k) {
    if (!node) return new Node(k);
    if (k < node->key) node->left = insert(node->left, k);
    else if (k > node->key) node->right = insert(node->right, k);
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bal = getBal(node);
    if (bal > 1 && k < node->left->key) return rotRight(node);
    if (bal < -1 && k > node->right->key) return rotLeft(node);
    if (bal > 1 && k > node->left->key) {
        node->left = rotLeft(node->left);
        return rotRight(node);
    }
    if (bal < -1 && k < node->right->key) {
        node->right = rotRight(node->right);
        return rotLeft(node);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* curr = node;
    while (curr->left) curr = curr->left;
    return curr;
}

Node* deleteNode(Node* root, int k) {
    if (!root) return root;
    if (k < root->key) root->left = deleteNode(root->left, k);
    else if (k > root->key) root->right = deleteNode(root->right, k);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    if (!root) return root;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bal = getBal(root);
    if (bal > 1 && getBal(root->left) >= 0) return rotRight(root);
    if (bal > 1 && getBal(root->left) < 0) {
        root->left = rotLeft(root->left);
        return rotRight(root);
    }
    if (bal < -1 && getBal(root->right) <= 0) return rotLeft(root);
    if (bal < -1 && getBal(root->right) > 0) {
        root->right = rotRight(root->right);
        return rotLeft(root);
    }
    return root;
}

void preOrder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->key << " ";
}

bool search(Node* root, int k) {
    if (!root) return false;
    if (root->key == k) return true;
    if (k < root->key) return search(root->left, k);
    return search(root->right, k);
}

Node* findKth(Node* root, int& k) {
    if (!root) return nullptr;
    Node* left = findKth(root->left, k);
    if (left) return left;
    if (--k == 0) return root;
    return findKth(root->right, k);
}

void heights(Node* root) {
    cout << "Left Height: " << getHeight(root->left) << "\nRight Height: " << getHeight(root->right) << endl;
}

int main() {
    Node* root = nullptr;
    int vals[] = {1, 2, 3, 4, 5, 6, 7};
    for (int v : vals) root = insert(root, v);
    
    cout << "Pre-order before deletion: "; preOrder(root); cout << endl;
    cout << "In-order before deletion: "; inOrder(root); cout << endl;
    cout << "Post-order before deletion: "; postOrder(root); cout << endl;

    root = deleteNode(root, 3);

    cout << "\nPre-order after deletion: "; preOrder(root); cout << endl;
    cout << "In-order after deletion: "; inOrder(root); cout << endl;
    cout << "Post-order after deletion: "; postOrder(root); cout << endl;

    //for a value notexisting
    int searchVal = 3;
    if (search(root, searchVal)) cout << "\nValue " << searchVal << " found.\n";
    else root = insert(root, searchVal), cout << "\nValue " << searchVal << " not found, so inserted.\n";

    //for a vlue existing (so found)
    searchVal = 4;
    if (search(root, searchVal)) cout << "\nValue " << searchVal << " found.\n";
    else root = insert(root, searchVal), cout << "\nValue " << searchVal << " inserted.\n";

    int k = 2;
    Node* kthSmallest = findKth(root, k);
    cout << "\n2nd Smallest: " << (kthSmallest ? kthSmallest->key : -1) << endl;

    k = 6;
    Node* kthLargest = findKth(root, k);
    cout << "6th Largest: " << (kthLargest ? kthLargest->key : -1) << endl;

    heights(root);

    return 0;
}

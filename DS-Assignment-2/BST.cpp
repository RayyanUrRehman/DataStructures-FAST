#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
    int id;
    string name;
    int age;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int _id, string _name, int _age)
        : id(_id), name(_name), age(_age), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;

    BSTNode* insert(BSTNode* node, int id, string name, int age) {
        if (node == nullptr) return new BSTNode(id, name, age);
        if (id < node->id) node->left = insert(node->left, id, name, age);
        else node->right = insert(node->right, id, name, age);
        return node;
    }

    BSTNode* search(BSTNode* node, int id) {
        if (node == nullptr || node->id == id) return node;
        if (id < node->id) return search(node->left, id);
        return search(node->right, id);
    }

    BSTNode* findMin(BSTNode* node) {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }

    BSTNode* deleteNode(BSTNode* node, int id) {
        if (node == nullptr) return node;
        if (id < node->id) node->left = deleteNode(node->left, id);
        else if (id > node->id) node->right = deleteNode(node->right, id);
        else {
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            BSTNode* temp = findMin(node->right);
            node->id = temp->id;
            node->name = temp->name;
            node->age = temp->age;
            node->right = deleteNode(node->right, temp->id);
        }
        return node;
    }

    void inorderTraversal(BSTNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", Age: " << node->age << endl;
            inorderTraversal(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int id, string name, int age) {
        root = insert(root, id, name, age);
    }

    BSTNode* search(int id) {
        return search(root, id);
    }

    void update(int id, string newName, int newAge) {
        BSTNode* node = search(id);
        if (node) {
            node->name = newName;
            node->age = newAge;
        }
    }

    void deleteNode(int id) {
        root = deleteNode(root, id);
    }

    void display() {
        inorderTraversal(root);
    }
};

int main() {
    BST bst;
    bst.insert(1, "Alice", 25);
    bst.insert(2, "Bob", 30);
    bst.insert(3, "Charlie", 35);

    cout << "Initial Records:" << endl;
    bst.display();

    cout << "\nUpdating Bob's age to 32..." << endl;
    bst.update(2, "Bob", 32);
    bst.display();

    cout << "\nDeleting Alice..." << endl;
    bst.deleteNode(1);
    bst.display();

    return 0;
}
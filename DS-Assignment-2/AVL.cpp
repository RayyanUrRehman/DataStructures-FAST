#include <iostream>
#include <string>
using namespace std;

struct AVLNode {
    int id;
    string name;
    int age;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int _id, string _name, int _age)
        : id(_id), name(_name), age(_age), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
    private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    AVLNode* insert(AVLNode* node, int id, string name, int age) {
        if (node == nullptr) return new AVLNode(id, name, age);

        if (id < node->id)
            node->left = insert(node->left, id, name, age);
        else if (id > node->id)
            node->right = insert(node->right, id, name, age);
        else
            return node; // Duplicate keys not allowed

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && id < node->left->id)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && id > node->right->id)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && id > node->left->id) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && id < node->right->id) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVLNode* search(AVLNode* node, int id) {
        if (node == nullptr || node->id == id)
            return node;

        if (id < node->id)
            return search(node->left, id);
        return search(node->right, id);
    }

    void inorderTraversal(AVLNode* node) {
        if (node) {
            inorderTraversal(node->left);
            cout << "ID: " << node->id << ", Name: " << node->name << ", Age: " << node->age << endl;
            inorderTraversal(node->right);
        }
    }

    public:
    AVLTree() : root(nullptr) {}

    void insert(int id, string name, int age) {
        root = insert(root, id, name, age);
    }

    AVLNode* search(int id) {
        return search(root, id);
    }

    void display() {
        inorderTraversal(root);
    }
};

int main() {
    AVLTree avl;
    avl.insert(1, "Rayyan", 25);
    avl.insert(2, "Sufyan", 30);
    avl.insert(3, "Azlaan", 35);

    cout << "AVL Tree Records:" << endl;
    avl.display();

    return 0;
}
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <tuple>
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
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalanceFactor(node);

        if (balance > 1 && id < node->left->id)
            return rotateRight(node);

        if (balance < -1 && id > node->right->id)
            return rotateLeft(node);

        if (balance > 1 && id > node->left->id) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

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
    const int datasetSize = 1000;
    vector<tuple<int, string, int>> data;

    srand(time(nullptr));
    for (int i = 0; i < datasetSize; ++i) {
        int id = rand() % 10000;
        string name = "Name" + to_string(i);
        int value = rand() % 1000;
        data.emplace_back(id, name, value);
    }

    AVLTree avl;

    auto startInsertion = chrono::high_resolution_clock::now();
    for (const auto& record : data) {
        avl.insert(get<0>(record), get<1>(record), get<2>(record));
    }
    auto endInsertion = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> insertionTime = endInsertion - startInsertion;

    cout << "Insertion Time: " << insertionTime.count() << " ms" << endl;

    const int numSearches = 10000;
    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 0; i < numSearches; ++i) {
        int randomIndex = rand() % datasetSize;
        avl.search(get<0>(data[randomIndex]));
    }
    auto endSearch = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> searchTime = endSearch - startSearch;

    cout << "Search Time for " << numSearches << " searches: " << searchTime.count() << " ms" << endl;

    return 0;
}

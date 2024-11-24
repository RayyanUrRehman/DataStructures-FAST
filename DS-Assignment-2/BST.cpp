#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

class BST {
private:
    struct Node {
        int key;
        string name;
        int value;
        Node* left;
        Node* right;

        Node(int k, const string& n, int v) : key(k), name(n), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int key, const string& name, int value) {
        if (!node) {
            node = new Node(key, name, value);
        } else if (key < node->key) {
            insert(node->left, key, name, value);
        } else {
            insert(node->right, key, name, value);
        }
    }

    bool search(Node* node, int key) const {
        if (!node) return false;
        if (key == node->key) return true;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr) {}

    ~BST() {
        clear(root);
    }

    void insert(int key, const string& name, int value) {
        insert(root, key, name, value);
    }

    bool search(int key) const {
        return search(root, key);
    }
};

int main() {
    const int datasetSize = 10000;
    vector<tuple<int, string, int>> data;

    srand(time(nullptr));
    for (int i = 0; i < datasetSize; ++i) {
        int id = rand() % 10000;
        string name = "Name" + to_string(i);
        int value = rand() % 1000;
        data.emplace_back(id, name, value);
    }

    BST bst;

    auto startInsertion = chrono::high_resolution_clock::now();
    for (const auto& record : data) {
        bst.insert(get<0>(record), get<1>(record), get<2>(record));
    }
    auto endInsertion = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> insertionTime = endInsertion - startInsertion;

    cout << "Insertion Time: " << insertionTime.count() << " ms" << endl;

    const int numSearches = 10000;
    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 0; i < numSearches; ++i) {
        int randomIndex = rand() % datasetSize;
        bst.search(get<0>(data[randomIndex]));
    }
    auto endSearch = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> searchTime = endSearch - startSearch;

    cout << "Search Time for " << numSearches << " searches: " << searchTime.count() << " ms" << endl;

    return 0;
}

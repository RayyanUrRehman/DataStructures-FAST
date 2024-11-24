#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
using namespace std;

class BTreeNode {
public:
    vector<int> keys;
    vector<string> names;
    vector<int> ages;
    vector<BTreeNode*> children;
    bool isLeaf;
    int minDegree;

    BTreeNode(int _minDegree, bool _isLeaf) 
        : minDegree(_minDegree), isLeaf(_isLeaf) {}

    void traverse() {
        int i;
        for (i = 0; i < keys.size(); i++) {
            if (!isLeaf) children[i]->traverse();
            cout << "ID: " << keys[i] << ", Name: " << names[i] 
                 << ", Age: " << ages[i] << endl;
        }
        if (!isLeaf) children[i]->traverse();
    }

    BTreeNode* search(int id) {
        int i = 0;
        while (i < keys.size() && id > keys[i]) i++;
        if (i < keys.size() && keys[i] == id) return this;
        if (isLeaf) return nullptr;
        return children[i]->search(id);
    }

    void insertNonFull(int id, string name, int age) {
        int i = keys.size() - 1;
        if (isLeaf) {
            while (i >= 0 && keys[i] > id) {
                i--;
            }
            keys.insert(keys.begin() + i + 1, id);
            names.insert(names.begin() + i + 1, name);
            ages.insert(ages.begin() + i + 1, age);
        } else {
            while (i >= 0 && keys[i] > id) {
                i--;
            }
            if (children[i + 1]->keys.size() == 2 * minDegree - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1] < id) i++;
            }
            children[i + 1]->insertNonFull(id, name, age);
        }
    }

    void splitChild(int i, BTreeNode* y) {
        BTreeNode* z = new BTreeNode(y->minDegree, y->isLeaf);
        z->keys.assign(y->keys.begin() + minDegree, y->keys.end());
        z->names.assign(y->names.begin() + minDegree, y->names.end());
        z->ages.assign(y->ages.begin() + minDegree, y->ages.end());
        y->keys.resize(minDegree - 1);
        y->names.resize(minDegree - 1);
        y->ages.resize(minDegree - 1);
        if (!y->isLeaf) {
            z->children.assign(y->children.begin() + minDegree, y->children.end());
            y->children.resize(minDegree);
        }
        children.insert(children.begin() + i + 1, z);
        keys.insert(keys.begin() + i, y->keys[minDegree - 1]);
        names.insert(names.begin() + i, y->names[minDegree - 1]);
        ages.insert(ages.begin() + i, y->ages[minDegree - 1]);
    }

    // Delete Operation
    void deleteKey(int id) {
        int i = 0;
        while (i < keys.size() && keys[i] < id) i++;

        if (i < keys.size() && keys[i] == id) {  // Key found
            if (isLeaf) {  // Case 1: Leaf node
                keys.erase(keys.begin() + i);
                names.erase(names.begin() + i);
                ages.erase(ages.begin() + i);
            } else {  // Case 2: Internal node
                BTreeNode* pred = children[i];
                BTreeNode* succ = children[i + 1];
                
                if (pred->keys.size() >= minDegree) {
                    // Predecessor has enough keys
                    int predKey = pred->keys.back();
                    string predName = pred->names.back();
                    int predAge = pred->ages.back();
                    pred->deleteKey(predKey);
                    keys[i] = predKey;
                    names[i] = predName;
                    ages[i] = predAge;
                } else if (succ->keys.size() >= minDegree) {
                    // Successor has enough keys
                    int succKey = succ->keys.front();
                    string succName = succ->names.front();
                    int succAge = succ->ages.front();
                    succ->deleteKey(succKey);
                    keys[i] = succKey;
                    names[i] = succName;
                    ages[i] = succAge;
                } else {
                    // Merge the predecessor and successor
                    merge(i);
                    children[i]->deleteKey(id);
                }
            }
        } else if (!isLeaf) {
            children[i]->deleteKey(id);
        }
    }

    void merge(int i) {
        BTreeNode* child = children[i];
        BTreeNode* sibling = children[i + 1];

        child->keys.push_back(keys[i]);
        child->names.push_back(names[i]);
        child->ages.push_back(ages[i]);

        child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
        child->names.insert(child->names.end(), sibling->names.begin(), sibling->names.end());
        child->ages.insert(child->ages.end(), sibling->ages.begin(), sibling->ages.end());

        if (!child->isLeaf) {
            child->children.insert(child->children.end(), sibling->children.begin(), sibling->children.end());
        }

        keys.erase(keys.begin() + i);
        names.erase(names.begin() + i);
        ages.erase(ages.begin() + i);
        children.erase(children.begin() + i + 1);
    }
};

class BTree {
private:
    BTreeNode* root;
    int minDegree;

public:
    BTree(int _minDegree) : root(nullptr), minDegree(_minDegree) {}

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    BTreeNode* search(int id) {
        return (root == nullptr) ? nullptr : root->search(id);
    }

    void insert(int id, string name, int age) {
        if (root == nullptr) {
            root = new BTreeNode(minDegree, true);
            root->keys.push_back(id);
            root->names.push_back(name);
            root->ages.push_back(age);
        } else {
            if (root->keys.size() == 2 * minDegree - 1) {
                BTreeNode* newRoot = new BTreeNode(minDegree, false);
                newRoot->children.push_back(root);
                newRoot->splitChild(0, root);
                int i = (newRoot->keys[0] < id) ? 1 : 0;
                newRoot->children[i]->insertNonFull(id, name, age);
                root = newRoot;
            } else {
                root->insertNonFull(id, name, age);
            }
        }
    }

    void deleteKey(int id) {
        if (root != nullptr) {
            root->deleteKey(id);
            if (root->keys.empty()) {
                BTreeNode* oldRoot = root;
                root = (root->isLeaf) ? nullptr : root->children[0];
                delete oldRoot;
            }
        }
    }
};

int main() {
    const int datasetSize = 10000;
    const int numSearches = 10000;
    const int numDeletions = 10000;

    BTree btree(3);

    // Insert
    auto startInsert = chrono::high_resolution_clock::now();
    for (int i = 1; i <= datasetSize; ++i) {
        int id = i;
        string name = "Name" + to_string(i);
        int age = rand() % 100;
        btree.insert(id, name, age);
    }
    auto endInsert = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> insertTime = endInsert - startInsert;
    cout << "Insertion Time for " << datasetSize << " records: " << insertTime.count() << " ms" << endl;

    // Search
    auto startSearch = chrono::high_resolution_clock::now();
    for (int i = 0; i < numSearches; ++i) {
        int randomId = rand() % datasetSize + 1;
        btree.search(randomId);
    }
    auto endSearch = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> searchTime = endSearch - startSearch;
    cout << "Total Search Time for " << numSearches << " searches: " << searchTime.count() << " ms" << endl;
    cout << "Average Time per Search: " << (searchTime.count() / numSearches) << " ms" << endl;

    // Delete
    auto startDelete = chrono::high_resolution_clock::now();
    for (int i = 0; i < numDeletions; ++i) {
        int randomId = rand() % datasetSize + 1;
        btree.deleteKey(randomId);
    }
    auto endDelete = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> deleteTime = endDelete - startDelete;
    cout << "Total Delete Time for " << numDeletions << " deletions: " << deleteTime.count() << " ms" << endl;
    cout << "Average Time per Deletion: " << (deleteTime.count() / numDeletions) << " ms" << endl;

    return 0;
}

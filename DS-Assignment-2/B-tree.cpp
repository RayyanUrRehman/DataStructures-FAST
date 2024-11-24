#include <iostream>
#include <vector>
#include <string>
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
};

int main() {
    BTree btree(3);


    btree.insert(10, "Rayyan", 25);
    btree.insert(20, "Sufyan", 30);
    btree.insert(5, "Azlaan", 35);
    btree.insert(6, "Adil", 28);
    btree.insert(12, "Shayan", 24);
    btree.insert(30, "Obaid", 40);
    btree.insert(7, "Ali", 22);

    cout << "Traversing B-Tree:" << endl;
    btree.traverse();

    int searchId = 12;
    BTreeNode* result = btree.search(searchId);
    if (result) {
        cout << "\nRecord Found: ID = " << searchId << endl;
    } else {
        cout << "\nRecord with ID = " << searchId << " not found." << endl;
    }

    return 0;
}
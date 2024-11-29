#include <iostream>
using namespace std;
#define MAX 14

struct Node {
  Node *left;
  Node *right;
  int data;
  int height;
  Node(int d) : data(d), height(1), left(NULL), right(NULL) {}
};

class AVL {
  Node *root;

public:
  AVL() : root(NULL) {}
  void insert(int data) { root = insert(root, data); }
  int search(int data) { return search(root, data) != nullptr ? 1 : 0; }
  void deleteNode(int data) { root = deleteNode(root, data); }

  void printPreOrder() {
    printPreOrder(root);
    cout << endl;
  }

  void printInOrder() {
    printInOrder(root);
    cout << endl;
  }

  void printPostOrder() {
    printPostOrder(root);
    cout << endl;
  }

private:
  Node *search(Node *root, int data) {
    if (root == NULL)
      return nullptr;
    if (data == root->data)
      return root;
    if (data < root->data)
      return search(root->left, data);
    else
      return search(root->right, data);
  }
  void printPreOrder(Node *root) {
    if (!root)
      return;
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
  void printInOrder(Node *root) {
    if (!root)
      return;
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
  }
  void printPostOrder(Node *root) {
    if (!root)
      return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
  }

  Node *insert(Node *root, int data) {
    if (!root)
      return new Node(data);

    if (data < root->data)
      root->left = insert(root->left, data);
    else if (data > root->data)
      root->right = insert(root->right, data);
    else {
      // Ambigous representation of index - Considered as height level
      cout << root->data << " already exists" << endl;
      cout << root->height << " Relative Height" << endl;
    }

    updateHeight(root);
    balance(root);
    return root;
  }

  void updateHeight(Node *root) {
    root->height = max(height(root->left), height(root->right)) + 1;
  }

  Node *leftRotate(Node *root) {
    Node *rchild = root->right;
    Node *rchildLeft = rchild->left;
    root->right = rchildLeft;
    rchild->left = root;

    updateHeight(root);
    updateHeight(rchild);
    return rchild;
  }

  Node *rightRotate(Node *root) {
    Node *lchild = root->left;
    Node *lchildRight = lchild->right;
    root->left = lchildRight;
    lchild->right = root;

    updateHeight(root);
    updateHeight(lchild);
    return lchild;
  }

  void balance(Node *&root) {
    int balanceFactor = height(root->left) - height(root->right);

    if (balanceFactor > 1) {
      // Left Left
      if (height(root->left->left) >= height(root->left->right)) {
        root = rightRotate(root);
      } else {
        // Left Right
        root->left = leftRotate(root->left);
        root = rightRotate(root);
      }
    } else if (balanceFactor < -1) {

      // Right Right
      if (height(root->right->right) >= height(root->right->left)) {
        root = leftRotate(root);
      } else {
        // Right Left
        root->right = rightRotate(root->right);
        root = leftRotate(root);
      }
    }
  }

  int height(Node *root) { return root ? root->height : 0; }

  Node *deleteNode(Node *root, int data) {
    if (!root)
      return NULL;

    if (data < root->data) {
      root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
      root->right = deleteNode(root->right, data);
    } else {
      if (!root->left || !root->right) {
        Node *temp = root->left ? root->left : root->right;
        delete root;
        root = temp;
      } else {
        Node *temp = root->right;
        while (temp->left) {
          temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
      }
    }

    if (root) {
      updateHeight(root);
      balance(root);
    }
    return root;
  }
};

class HashTable {
  AVL *a;

public:
  HashTable() { a = new AVL[MAX](); }
  int Hash(int d) { return abs(d) % MAX; }

  void insert(int d) {
    int hash = Hash(d);
    a[hash].insert(d);
  }

  int search(int d) {
    int hash = Hash(d);

    return a[hash].search(d);
  }

  void erase(int &d) {
    int hash = Hash(d);
    a[hash].deleteNode(d);
  }

  void print() {
    for (int i = 0; i < MAX; i++) {
      cout << i << " -> ";
      a[i].printPreOrder();
    }
  }

  ~HashTable() {
    delete[] a;
  }
};

int main() {
  char nuts[] = {'@', '%', '$', '#', '^'};
  char bolts[] = {'%', '@', '#', '$', '^'};
  HashTable map;
  int n = sizeof(nuts) / sizeof(nuts[0]);
  for (int i = 0; i < n; i++) {
    map.insert(nuts[i]);
  }
  
  for (int i = 0; i < n; i++) {
    if (map.search(bolts[i])){
      nuts[i] = bolts[i];
    };
  }

  for (int i = 0; i < n; i++)
    cout << nuts[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++)
    cout << bolts[i] << " ";
  cout << endl;

  return 0;
}
#include <iostream>
using namespace std;
#define MAX 10

class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = NULL;
  }
};

class LL {
public:
  Node *head;
  Node *tail;
  LL() {
    head = NULL;
    tail = NULL;
  }
  void insert_end(int data) {
    Node *new_node = new Node(data);
    if (!head) {
      head = tail = new_node;
    } else {
      tail->next = new_node;
      tail = new_node;
    }
  }

  void print() {
    Node *cur = head;
    while (cur) {
      cout << cur->data << " ";
      cur = cur->next;
    }
    cout << endl;
  }
  Node *search(int key) { return search(head, key); }
  void delete_node(int key) {
    if (!head)
      return;

    if (head->data == key) {
      Node *temp = head;
      head = head->next;
      delete temp;
      if (!head)
        tail = NULL;
      return;
    }

    Node *cur = head;
    while (cur->next && cur->next->data != key) {
      cur = cur->next;
    }

    if (cur->next) {
      Node *temp = cur->next;
      cur->next = cur->next->next;
      if (temp == tail)
        tail = cur;
      delete temp;
    }
  }
  Node *search(Node *cur, int key) {
    if (cur == nullptr) {
      return NULL;
    }
    if (cur->data == key) {
      return cur;
    }
    Node *next = search(cur->next, key);
    return next;
  }
};

class HashTable {
  LL *a;

public:
  HashTable() { a = new LL[MAX](); }
  int Hash(int v) { return v % MAX; }
  void insert(int &d) {
    // LP
    int hash = Hash(d);
    a[hash].insert_end(d);
  }

  int search(int &d) {
    int hash = Hash(d);

    return a[hash].search(hash)->data;
  }

  void erase(int v) {
    int hash = Hash(v);
    a[hash].delete_node(v);
  }

  void print() {
    for (int i = 0; i < MAX; i++) {
      cout << i << ": ";
      a[i].print();
    };
  }
  ~HashTable() { delete[] a; }
};

int main(int argc, char *argv[]) {
  int a[] = {20, 34, 45, 70, 56};
  HashTable map;
  int n = sizeof(a) / sizeof(int);
  for (int i = 0; i < n; i++) {
    map.insert(a[i]);
  }
  map.print();
  map.erase(20);
  map.print();
  map.erase(70);
  map.print();
  return 0;
}
#include <iostream>
using namespace std;
#define MAX 14

class Data {
public:
  int v;
  Data(int v) : v(v) {}
};

class HashTable {
  Data **a;

public:
  HashTable() { a = new Data *[MAX](); }
  int Hash(Data d) { return d.v % MAX; }
  void insert(Data &d) {
    int hash = Hash(d);
    int vis[MAX] = {0};
    while (a[hash] != nullptr && !vis[hash]) {
      vis[hash] = 1;
      hash = (hash + 1) % MAX;
    }
    if (vis[hash]) {
      cerr << "Hash table is full" << endl;
      return;
    }
    a[hash] = new Data(d);
  }

  Data *search(Data &d) {
    int hash = Hash(d);
    int vis[MAX] = {0};
    while (a[hash] != nullptr && a[hash]->v != d.v && !vis[hash]) {
      vis[hash] = 1;
      cout << "vis[" << hash << "] = " << vis[hash] << endl;
      hash = (hash + 1) % MAX;
    }
    if (vis[hash] || a[hash] == nullptr)
      return nullptr;
    return a[hash];
  }

  void erase(Data &d) {
    int hash = Hash(d);
    while (a[hash] != nullptr && a[hash]->v != d.v)
      hash = (hash + 1) % MAX;
    if (a[hash] != nullptr) {
      delete a[hash];
      a[hash] = nullptr;
    }
  }

  void print() {
    for (int i = 0; i < MAX; i++)
      if (a[i] != nullptr)
        cout << i << " -> " << a[i]->v << endl;
  }

  ~HashTable() {
    for (int i = 0; i < MAX; i++)
      if (a[i] != nullptr)
        delete a[i];
    delete[] a;
  }
};

int twoSum(HashTable &map, int k, int *a, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // cout << i << " " << endl;
    if (k - a[i] < 0)
      continue;
    Data d(k - a[i]);
    if (map.search(d) != nullptr) {
      ans++;
      map.erase(d);
    }
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  int *a = new int[n];
  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int k;
  cout << "Enter the target sum: ";
  cin >> k;

  HashTable map;
  for (int i = 0; i < n; i++) {
    Data d(a[i]);
    map.insert(d);
  }

  cout << "Number of pairs with sum " << k << ": " << twoSum(map, k, a, n)
       << endl;

  delete[] a;
  return 0;
}
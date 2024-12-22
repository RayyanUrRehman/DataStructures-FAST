#include <climits>
#include <iostream>
using namespace std;

class MinHeap {
  int *heap;
  int capacity;
  int size;

  void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
      smallest = left;
    if (right < size && heap[right] < heap[smallest])
      smallest = right;

    if (smallest != index) {
      swap(heap[index], heap[smallest]);
      heapifyDown(smallest);
    }
  }

  void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] < heap[parent]) {
      swap(heap[index], heap[parent]);
      heapifyUp(parent);
    }
  }

public:
  MinHeap(int cap) : capacity(cap), size(0) { heap = new int[capacity]; }

  ~MinHeap() { delete[] heap; }

  void insert(int val) {
    if (size == capacity) {
      cout << "Heap overflow. Cannot insert." << endl;
      return;
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
  }

  int extractMin() {
    if (size == 0)
      return INT_MAX;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};

class MaxHeap {
  int *heap;
  int capacity;
  int size;

  void heapifyDown(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest])
      largest = left;
    if (right < size && heap[right] > heap[largest])
      largest = right;

    if (largest != index) {
      swap(heap[index], heap[largest]);
      heapifyDown(largest);
    }
  }

  void heapifyUp(int index) {
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] > heap[parent]) {
      swap(heap[index], heap[parent]);
      heapifyUp(parent);
    }
  }

public:
  MaxHeap(int cap) : capacity(cap), size(0) { heap = new int[capacity]; }

  ~MaxHeap() { delete[] heap; }

  void insert(int val) {
    if (size == capacity) {
      cout << "Heap overflow. Cannot insert." << endl;
      return;
    }
    heap[size] = val;
    heapifyUp(size);
    size++;
  }

  int extractMax() {
    if (size == 0)
      return INT_MIN;
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
    return root;
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << heap[i] << " ";
    }
    cout << endl;
  }
};
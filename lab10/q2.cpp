#include <iostream>
using namespace std;

class Heap {
public:
    int *arr;
    int size;
    int index;

    Heap(int s) {
        arr = new int[s];
        size = s;
        index = 0;
    }

    void insert(int val) {
        if (index == size) {
            cout << "Heap is Full " << endl;
            return;
        }
        arr[index] = val;

        int i = index;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                break;
            }
        }
        index++;
    }

    void heapifyDownMin(int *arr, int size, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < size && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifyDownMin(arr, size, smallest);
        }
    }

    void heapifyDownMax(int *arr, int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDownMax(arr, size, largest);
        }
    }

    void makeMinHeap(int *arr, int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDownMin(arr, size, i);
        }
    }

    void makeMaxHeap(int *arr, int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDownMax(arr, size, i);
        }
    }

    void heapSort(int *arr, int size) {
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapifyDownMax(arr, size, i);
        }

        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyDownMax(arr, i, 0);
        }
    }

    void deleteRoot(int &size) {
        arr[0] = arr[size - 1];
        size--;
        heapifyDownMin(arr, size, 0);
    }

    void print(int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h(10);

    h.insert(35);
    h.insert(33);
    h.insert(42);
    h.insert(10);
    h.insert(14);
    h.insert(19);
    h.insert(27);
    h.insert(44);
    h.insert(26);
    h.insert(31);

    cout << "Original Tree: ";
    h.print(h.index);

    h.makeMinHeap(h.arr, h.index);
    cout << "Min-Heap: ";
    h.print(h.index);

    h.deleteRoot(h.index);
    cout << "After Deleting Root (Min-Heap): ";
    h.print(h.index);

    h.makeMaxHeap(h.arr, h.index);
    cout << "Max-Heap: ";
    h.print(h.index);

    h.heapSort(h.arr, h.index);
    cout << "Sorted Output: ";
    h.print(h.index);

    return 0;
}

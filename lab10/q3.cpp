#include <iostream>
using namespace std;

class PQ {
public:
    int arr[100][2]; 
    int size;

    PQ() {
        size = 0;
    }

    void insertTask(int task_id, int priority) {
        arr[size][0] = priority;
        arr[size][1] = task_id;
        size++;
        heapifyUp(size - 1);
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent][0] < arr[index][0]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void deleteMax() {
        if (size == 0) {
            cout << "No tasks to delete." << endl;
            return;
        }

        cout << "Task " << arr[0][1] << " with priority " << arr[0][0] << " executed." << endl;

        arr[0][0] = arr[size - 1][0];
        arr[0][1] = arr[size - 1][1];
        size--;

        heapifyDown(0);
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && arr[left][0] > arr[largest][0]) {
            largest = left;
        }
        if (right < size && arr[right][0] > arr[largest][0]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapifyDown(largest);
        }
    }

    void printHeap() {
        cout << "Current Tasks in Heap (Priority, Task): ";
        for (int i = 0; i < size; i++) {
            cout << "(" << arr[i][0] << ", " << arr[i][1] << ") ";
        }
        cout << endl;
    }


    void swap(int a[2], int b[2]) {
        int tempPriority = a[0];
        int tempTask = a[1];
        a[0] = b[0];
        a[1] = b[1];
        b[0] = tempPriority;
        b[1] = tempTask;
    }
};

int main() {
    PQ pq;
    int numTasks;

    cout << "Enter the number of tasks: ";
    cin >> numTasks;

    for (int i = 1; i <= numTasks; i++) {
        int priority = (rand() % 10) + 1; 
        cout << "Task " << i << " assigned priority " << priority << "." << endl;
        pq.insertTask(i, priority);
    }

    pq.printHeap();

    cout << "Executing tasks in order of priority:" << endl;
    while (pq.size > 0) {
        pq.deleteMax();
    }

    return 0;
}

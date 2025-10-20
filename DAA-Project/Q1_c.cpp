#include <iostream>
using namespace std;

long long inversionCount = 0;

void mergeArrays(int arr[], int left, int mid, int right) {         // merging the two sorted halves and also counting inversions
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inversionCount += (n1 - i);
        }
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {        // dividing the array into two parts (using standard merge sort)
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArrays(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter array size (n >= 10): ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " numbers:\n";
    for(int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n - 1);

    cout << "Total number of inversions = " << inversionCount << endl;

    delete[] arr;
    return 0;
}



// 2. Recurrence Relation:
//    T(n) = 2T(n/2) + O(n) which solves to T(n) = O(n log n).



// 3. Comparison with Brute Force:
//    Brute force checks every pair and takes O(n^2).
//    Divide and conquer reduces this to O(n log n), which is much faster.


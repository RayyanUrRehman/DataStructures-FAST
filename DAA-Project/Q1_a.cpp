// 1.
#include <iostream>
using namespace std;

int comparisonCount = 0; 

pair<int, int> findMinMax(int arr[], int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]};
    }

    if (high == low + 1) {
        comparisonCount++;
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    int mid = (low + high) / 2;
    pair<int, int> left = findMinMax(arr, low, mid);
    pair<int, int> right = findMinMax(arr, mid + 1, high);

    comparisonCount++;
    int overallMin = (left.first < right.first) ? left.first : right.first;

    comparisonCount++;
    int overallMax = (left.second > right.second) ? left.second : right.second;

    return {overallMin, overallMax};
}

int main() {
    int n;
    cout << "Enter array size (n >= 10): ";
    cin >> n;

    if (n < 10) {
        cout << "Array size must be at least 10." << endl;
        return 0;
    }

    int* arr = new int[n];  

    cout << "Enter " << n << " elements:\n";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = findMinMax(arr, 0, n - 1);

    cout << "\nSmallest element = " << result.first;
    cout << "\nLargest element = " << result.second;
    cout << "\nTotal key comparisons = " << comparisonCount << endl;

    delete[] arr; 
    return 0;
}



// 2. Recurrence Relation:
// T(n) = 2T(n/2) + 2, and solving it for n = 2^k gives T(n) = 2n - 2 key comparisons.



// 3. Comparison with Brute Force:
// The brute force method takes 2(n - 1) comparisons while divide and conquer takes 2n - 2.
// Both are O(n), but divide and conquer uses slightly fewer comparisons theoretically.


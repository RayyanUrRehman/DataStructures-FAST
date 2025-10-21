// 1.
#include <iostream>
using namespace std;

int comparisonCount = 0; 

pair<int, int> findMinMax(int arr[], int min, int max) {
    if (min == max) {
        return {arr[min], arr[min]};
    }

    if (max == min + 1) {
        comparisonCount++;
        if (arr[min] < arr[max])
            return {arr[min], arr[max]};
        else
            return {arr[max], arr[min]};
    }

    int mid = (min + max) / 2;
    pair<int, int> left = findMinMax(arr, min, mid);
    pair<int, int> right = findMinMax(arr, mid + 1, max);

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


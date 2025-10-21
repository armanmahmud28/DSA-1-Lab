#include <iostream>
using namespace std;

// Function to sort array using insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to find the smallest difference
int findSmallestDifference(int arr[], int n) {
    int minDiff = arr[1] - arr[0];  // initialize with first difference

    for (int i = 1; i < n - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main() {
    int arr[] = {15, 7, 2, 12, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    int result = findSmallestDifference(arr, n);
    cout << "Smallest difference: " << result << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Function to sort an array using Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Step 1: Define arrays
    int a[] = {1, 16, 13, 14, 4};
    int b[] = {15, 12, 5, 3, 7};

    int sizeA = 5;
    int sizeB = 5;
    int totalSize = sizeA + sizeB;

    // Step 2: Create merged array
    int merged[totalSize];

    // Step 3: Copy elements from a
    for (int i = 0; i < sizeA; i++) {
        merged[i] = a[i];
    }

    // Step 4: Copy elements from b
    for (int i = 0; i < sizeB; i++) {
        merged[sizeA + i] = b[i];
    }

    // Step 5: Sort using bubble sort function
    bubbleSort(merged, totalSize);

    // Step 6: Print the sorted array
    cout << "Merged and Sorted Array: ";
    for (int i = 0; i < totalSize; i++) {
        cout << merged[i] << " ";
    }

    return 0;
}

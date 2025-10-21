#include <iostream>
using namespace std;

int binarySearchDescending(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            cout << "Target found at index: " << mid << endl;
            return mid;
        }

        // Notice the reversed logic
        if (arr[mid] < target) {
            high = mid - 1;  // Move left
        } else {
            low = mid + 1;   // Move right
        }
    }

    cout << "Target not found!" << endl;
    return -1;
}

int main() {
    int arr[] = {100, 90, 80, 70, 60, 50, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 70;

    binarySearchDescending(arr, n, target);

    return 0;
}

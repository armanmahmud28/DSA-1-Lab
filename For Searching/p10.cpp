#include <iostream>
using namespace std;

int findPeakIndex(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {  // strictly less, because we are finding peak
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {
            // Peak is on the right side
            low = mid + 1;
        } else {
            // Peak is on the left side or at mid
            high = mid;
        }
    }
    // low == high → peak index
    return low;
}

int main() {
    int arr[] = {1, 3, 5, 7, 6, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakIndex(arr, n);
    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << arr[peakIndex] << endl;

    return 0;
}

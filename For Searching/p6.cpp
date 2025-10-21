#include <iostream>
using namespace std;

int findFirst(int arr[], int n, int target) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1; // keep searching left
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int findLast(int arr[], int n, int target) {
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1; // keep searching right
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {5, 7, 7, 8, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int first = findFirst(arr, n, target);
    int last = findLast(arr, n, target);

    cout << "First and Last Position: (" << first << ", " << last << ")" << endl;

    return 0;
}

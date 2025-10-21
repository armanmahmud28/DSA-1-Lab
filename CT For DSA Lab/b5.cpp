#include <iostream>
using namespace std;

void sortByLength(string arr[], int n) {
    // Bubble Sort based on string length
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].length() > arr[j + 1].length()) {
                // Swap if current string is longer than the next
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string arr[] = {"apple", "bat", "carrot", "dog"};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortByLength(arr, n);

    //cout << "Sorted by length: ";
    for (int i = 0; i < n; i++) {
        cout << "\"" << arr[i] << "\"";
        if (i != n - 1) cout << ", ";
    }

    return 0;
}

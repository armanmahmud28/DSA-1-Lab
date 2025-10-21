#include <iostream>
using namespace std;

// Function to sort array based on frequency
void sortByFrequency(int a[], int n, int freq[]) {
    // Bubble sort inside function
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {

            // If frequency[j] < frequency[j+1], swap
            if (freq[a[j]] < freq[a[j + 1]]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
            // If frequency same, but number[j] > number[j+1], swap
            else if (freq[a[j]] == freq[a[j + 1]] && a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Step 1: Input array
    int a[] = {4, 3, 1, 6, 1, 3, 4, 4};
    int n = 8;  // size of array

    // Step 2: Count frequency
    int freq[100] = {0};  // assuming numbers are less than 100

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;   // increase count of this number
    }

    // Step 3: Call the function to sort
    sortByFrequency(a, n, freq);

    // Step 4: Print final array
    cout << "Output: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}



#include <iostream>  // to use cout and cin
using namespace std;

// Step 1: Create a function to sort the array (using bubble sort for simplicity)
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Swap if the number is bigger than the next one
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Step 2: Create a function to find the longest chain of numbers in a row
int longestConsecutive(int arr[], int size) {
    sortArray(arr, size);  // sort the array first

    int count = 1;    // this keeps track of current chain
    int maxCount = 1; // this stores the longest chain

    for (int i = 1; i < size; i++) {
        // Skip if number is the same
        if (arr[i] == arr[i - 1]) {
            continue;
        }

        // If current number is just after the previous one
        if (arr[i] == arr[i - 1] + 1) {
            count++;  // increase the current chain count
        } else {
            count = 1; // reset the count
        }

        // Update the longest chain
        if (count > maxCount) {
            maxCount = count;
        }
    }

    return maxCount;
}

// Step 3: Main function to test the above
int main() {
    int a1[] = {1, 9, 3, 10, 4, 20, 2};
    int size1 = 7;

    int a2[] = {3, 1};
    int size2 = 2;

    int result1 = longestConsecutive(a1, size1);
    int result2 = longestConsecutive(a2, size2);

    cout << "Result 1: " << result1 << endl;  // should print 4
    cout << "Result 2: " << result2 << endl;  // should print 1

    return 0;
}

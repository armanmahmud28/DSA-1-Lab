#include <iostream>
using namespace std;

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the median
/*float findMedian(int arr[], int n) {
    bubbleSort(arr, n); // Sort the array

    if (n % 2 != 0) {
        // Odd number of elements
        return arr[n / 2];
    } else {
        // Even number of elements
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}
*/
float findmid(int arr[],int n){
    bubbleSort(arr,n);
    if(n%2!==0){
        return arr[n/2];
    }

    else{
        return (arr[n/2-1]+arr[n/2]/2.0);
    }
}

int main() {
    int arr[] = {11, 9, 17, 15};  // change input here
    int n = sizeof(arr) / sizeof(arr[0]);

    float median = findmid(arr, n);
    cout << "Median: " << median << endl;

    return 0;
}

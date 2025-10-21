#include<iostream>
using namespace std;

void sortEvenOddIndex(int arr[], int n){
    // Store even and odd index values separately
    int even[100], odd[100];
    int e=0, o=0;

    for(int i=0; i<n; i++){
        if(i%2==0){
            even[e++] = arr[i];  // even index
        } else {
            odd[o++] = arr[i];   // odd index
        }
    }

    // Sort even[] in ascending order
    for(int i=0; i<e-1; i++){
        for(int j=0; j<e-i-1; j++){
            if(even[j] > even[j+1]){
                int temp = even[j];
                even[j] = even[j+1];
                even[j+1] = temp;
            }
        }
    }

    // Sort odd[] in descending order
    for(int i=0; i<o-1; i++){
        for(int j=0; j<o-i-1; j++){
            if(odd[j] < odd[j+1]){
                int temp = odd[j];
                odd[j] = odd[j+1];
                odd[j+1] = temp;
            }
        }
    }

    // Put values back in original array
    e = 0;
    o = 0;
    for(int i=0; i<n; i++){
        if(i%2==0){
            arr[i] = even[e++];
        } else {
            arr[i] = odd[o++];
        }
    }
}

int main(){
    int arr[] = {16,17,4,18,1,20,5,12};
    int n = sizeof(arr)/sizeof(arr[0]);

    sortEvenOddIndex(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

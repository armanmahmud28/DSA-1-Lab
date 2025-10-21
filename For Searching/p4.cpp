#include<iostream>
using namespace std;
int search(int arr[],int n,int target)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid = low +(high-low)/2;

        if(arr[mid]==target)
        {
            cout<<"Output: "<<mid<<endl;
            return mid;
        
        }
            if(mid<target)
            {
            low = mid+1;
            }
            else{
            high = mid -1;
            }
            return -1;

    }
}

int main()
{
    int arr[] ={1, 3, 5, 7, 9};
    int n= sizeof(arr)/sizeof(arr[0]);
int target = 5;
search(arr,n,target);


    }

#include<iostream>

using namespace std;

void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;

    }
}

void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_idx=i;

        for(int j=i+1; j<n; j++)
        {
            if(arr[min_idx]<arr[j])
            {
                min_idx=j;
            }
        }

        int temp= arr[i];
        arr[i]=arr[min_idx];
        arr[min_idx]=temp;


    }
}

void bubble_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1 ;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


int main()
{
    int arr[]= {5,4,1,3,2};

    insertion_sort(arr, 5);

    //selection_sort(arr, 5);

    //bubble_sort(arr,5);



    for(int i=0; i<5; i++)
    {
        cout<<arr[i]<<" ";
    }
}

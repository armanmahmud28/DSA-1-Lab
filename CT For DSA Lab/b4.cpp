#include<iostream>
using namespace std;

void findnumber(int arr[],int n){


for(int i=0;i<n-1;i++){
for(int j=0;j<n-i-1;j++){
if(abs(arr[j])>abs(arr[j+1])){
    int temp =arr[j];

    arr[j]=arr[j+1];
    arr[j+1]=temp;
}


}


}
}
int main(){
    int arr[]={-10,5,-3,7,-2};
    int n=sizeof(arr)/sizeof(arr[0]);
    //int n1=sizeof(arr)/sizeof(arr[0]);
findnumber(arr,n);

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
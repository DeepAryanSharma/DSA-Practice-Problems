#include<iostream>
using namespace std;

int partition(int* arr, int s, int e){
    int pivotIndex=s;
    int pivot=arr[pivotIndex];

    //placing pivot element on the right position
    int count=0;
    for(int i=s+1; i<=e ; i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    swap(arr[pivotIndex],arr[s+count]);
    pivotIndex=s+count;

    //ensuring that all the elements in left side of the pivot should be less than pivot and on the right side should be greater than pivot
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }

        if(i< pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;

}

void quickSort(int* arr, int s, int e){

    //base case
    if(s>=e){
        return;
    }

    //partition logic,return pivot index
    int p=partition(arr,s,e);

    //recursive call for left partition
    quickSort(arr,s,p);

    //recursive call for right partition
    quickSort(arr,p+1,e);

}



int main(){
    int arr[]={2,3,1,2,3,6,5,47,89};
    int n=9;
    int s=0;
    int e=n-1;

    quickSort(arr,s,e);

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

}
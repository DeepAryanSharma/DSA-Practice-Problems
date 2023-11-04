#include<iostream>
using namespace std;

void merge(int* arr, int s, int e ){
    int mid= s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;

    //create two arrays of len1 and len2 lengths
    int *left= new int[len1];
    int *right=new int[len2];

    //copy values
    int k=s;
    for(int i=0 ; i<len1 ; i++){
        left[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0 ; i<len2; i++){
        right[i]=arr[k];
        k++;
    }

    //merge logic
    int leftIndex=0;
    int rightIndex=0;
    int mainArrayIndex=s;

    while(leftIndex<len1 && rightIndex<len2){
        if(left[leftIndex]<right[rightIndex]){
            arr[mainArrayIndex]=left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex]=right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    //if any of the array finished
    //->if right array is finished
    while(leftIndex<len1){
        arr[mainArrayIndex++]=left[leftIndex++];
    }
    //->if left array is finished
    while(rightIndex<len2){
        arr[mainArrayIndex++]=right[rightIndex++];
    }
}

void mergeSort(int* arr, int s, int e){
    //base case
    //if s==e -> only single element is present and an array with single element is considered as sorted
    //if s>e -> invalid array 
    if(s>=e){
        return;
    }

    //find mid in order to divide the given array in two halves
    int mid=s+(e-s)/2;

    //sort the left array using recursion
    mergeSort(arr, s, mid);

    //sort the right part
    mergeSort(arr, mid+1, e);

    //merge the two sorted arrays
    merge(arr, s, e);

}


int main(){
    int arr[]={5,2,3,15,45,75,2,3,1};
    int n=9;
    int s=0;
    int e=n-1;

    mergeSort(arr, s, e);

    //printing the sorted array
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}
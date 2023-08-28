#include<iostream>
#include <vector>
using namespace std;

void SortOnesAndZeroes(vector<int> arr){

  int left=0;
  int right=arr.size()-1;
  int i=0;
  while(i!=right){
    if(arr[i]==0){
      swap(arr[i],arr[left]);
      left++;
      i++;
    }
    else{
      swap(arr[i],arr[right]);
      right--;
      
    }
  } 

  //printing the answer
  for(int i = 0 ; i<arr.size() ; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  int n;
  cout<<"enter the size of the array: ";
  cin>>n;
  vector<int> arr(n);
  
  cout<<endl<<"Enter the elements of the array: ";
  for(int i=0 ; i<arr.size() ; i++){
    cin>>arr[i];
  }

  cout<<endl<<"Sorted array: ";
  SortOnesAndZeroes(arr);
  
  
  
}

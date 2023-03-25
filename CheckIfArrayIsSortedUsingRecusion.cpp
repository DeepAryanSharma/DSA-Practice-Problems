#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr, int n, int i){
  //base case
  if(i == n-1){
    return true;
  }
  //1 case solve kardo
  if(arr[i] > arr[i+1]){
    return false;
  }
  //baaki recursion sambhal lega
  isSorted(arr, n , i+1);
}

int main(){
  vector<int> v = {10,20,30,40,50};
  int n = v.size();
  int i=0;
  bool ans = isSorted(v, n, i);

  if(ans){
    cout<<"The array is sorted.";
  }
  else{
    cout<<"The array is not sorted.";
  }

  return 0;
  
}

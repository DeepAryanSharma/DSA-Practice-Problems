#include<iostream>
#include<vector>
using namespace std;

void MoveNegativesToLeft(vector<int> arr){
  int i=0, left=0;
  while(i<arr.size()){
    if(arr[i]<0){
      swap(arr[i], arr[left]);
      left++;
      i++;
    }
    else{
      i++;
    }
  }

  //printing
  for(int i=0 ; i<arr.size() ; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  vector<int> arr={2,3,-5,-6,5,9,-1};

  cout<<"sorted array: ";

  MoveNegativesToLeft(arr);
}
#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> arr, int target){
  int s=0;
  int e= arr.size()-1;
  int mid=s+(e-s)/2;
  int ans=-1

  while(s<=e){
    if(arr[mid]==target){
      //store the answer
      ans=mid;
      //further search in left
      e=mid-1;
    }

    else if(arr[mid]<target){
      //search in right
      s=mid+1;
    }

    else if(arr[mid]>target){
      //search in left
      e=mid-1;
    }
    //update mid
    mid=s+(e-s)/2;
  }
  return ans;
}

int main(){
  vector<int> arr{0,3,4,4,4,5,6,8,8,9};
  int target=4;

  int ans=firstOccurence(arr, target);
  cout<<"Answer is: "<<ans;
}

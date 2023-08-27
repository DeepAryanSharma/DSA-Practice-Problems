#include<iostream>
#include<vector>
using namespace std;

int lastOccurence(vector<int> arr, int target){
  int s=0;
  int e=arr.size()-1;
  int mid=s+(e-s)/2;
  int ans=-1;

  while(s<=e){
    if(target==arr[mid]){
      //store the answer
      ans=mid;
      //further search in right
      s=mid+1;
    }

    else if(target<arr[mid]){
      //search in left
      e=mid-1;
    }

    else if(target>arr[mid]){
      s=mid+1;
    }
    //update mid
    mid=s+(e-s)/2;
  }
  return ans;
}
int main(){
  vector<int> arr{1,2,2,2,2,2,3,3,4,5,6,7,7,7,7,8};
  int target=7;
  int ans=lastOccurence(arr, target);

  cout<<"The last occurence of "<<target<<" is: "<<ans;
}

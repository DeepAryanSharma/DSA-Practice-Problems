#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int> arr){
  for(int i=0 ; i< arr.size() ; i++){
    int index=abs(arr[i]);

    if(arr[index]>0){
      //marking the visited number
      arr[index]=-1*arr[index];
      
    }
    else{
      return index;
    }
  }
}

int main(){
  int n=4;
  vector<int> arr={1,3,4,2,2};

  int ans=findDuplicate(arr);

  cout<<"The duplicate number is: "<<ans;
  
}
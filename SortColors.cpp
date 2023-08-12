#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int> arr){
  int l=0,m=0;
  int h=arr.size()-1;

  while(m<=h){
    if(arr[m]==0){
      swap(arr[m], arr[l]);
      l++;
      m++;
    }

    else if(arr[m]==1){
      m++;
    }

    else{
      swap(arr[m], arr[h]);
      h--;
    }
 }
  //printing the answer
  for(int i=0; i<arr.size() ; i++){
    cout<<arr[i]<<" ";
  }
}

int main(){
  vector<int> arr={1,2,0,1,0,2,0,0};
  
  sortColors(arr);
  
}

#include<iostream>
#include<vector>
using namespace std;

int main(){
  int arr[]={2,4,6,8};
  int sizea=4;

  int brr[]={1,3,7};
  int sizeb=3;

  vector<int> ans;

  //pushing elements of arr in ans
  for(int i=0 ; i<sizea ; i++){
    ans.push_back(arr[i]);
  }

   //pushing elements of brr in ans
  for(int i=0 ; i<sizeb ; i++){
    ans.push_back(brr[i]);
  }

  //printing the elements of ans
  for(int i=0 ; i<ans.size() ; i++){
    cout<<ans[i]<<" ";
  }

  return 0 ;
}

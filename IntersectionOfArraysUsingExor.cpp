#include<iostream>
#include <vector>
using namespace std;

void intersectionArray(int arr[], int size1, int arr1[], int size2){
  vector<int> ans;
  for(int i=0; i<size1 ; i++){
    for(int j=0 ; j<size2 ; j++){

      int ex= arr[i]^arr1[j];
      if(ex==0){
        ans.push_back(arr[i]);

        //marking the elements to avoid duplication
        arr1[j]= -1*arr1[j];
        arr[i]= -1*arr[i];
      }
      
    }
  }
  // printing the answer array
  for(int i=0 ; i< ans.size() ; i++){
    cout<<ans[i]<<" "; 
  }


}

int main(){
  int arr[5]={1,2,3,4,5};
  int arr1[6]={4,2,3,3,4,8};

  cout<<"intersection of the given arrays is: ";
  intersectionArray(arr,5, arr1,6);
}

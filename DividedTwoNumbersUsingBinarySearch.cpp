#include<iostream>
using namespace std;

int division(int dividend, int divisor){
  int s=0;
  int e=abs(dividend);
  int mid=s+(e-s)/2;
  int ans=0;

  while(s<=e){
    if(abs(mid*divisor)==abs(dividend)){
      ans=mid;
      break;
    }

    if(abs(mid*divisor)<abs(dividend)){
      //store
      ans=mid;
      //further search in right
      s=mid+1;
    }

    else{
      //search in left
      e=mid-1;
    }
    //updating mid
    mid=s+(e-s)/2;
  }
  //determining the sign of the quotient 
  if((dividend<0 && divisor<0) || (dividend>0 && divisor>0)){
    return ans;
  }
  else{
    return -ans;
  }
}

int main(){
  int dividend=20;
  int divisor=5;
  
  cout<<division(dividend, divisor);
  
  
}

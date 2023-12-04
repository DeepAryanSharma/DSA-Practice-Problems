#include<iostream>
#include<string>
using namespace std;

void permutationStrings(string &str, int i){
    //base case
    if(i>=str.length()){
        cout<<str<<" ";
        return;
    }

    for(int j=i ; j<str.length() ; j++ ){
        //swapping
        swap(str[i], str[j]);
        //recrusive call
        permutationStrings(str,i+1);
        //backtracking to create original string
        swap(str[i],str[j]);

    }
}

int main(){
    string str="abc";
    int i=0;

    permutationStrings(str, i);

}
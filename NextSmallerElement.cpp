#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> input;
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    input.push_back(3);
    
    //printing input
    cout<<"input:"<<" ";
    for(int i=0 ; i<input.size() ; i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;

    vector<int> ans(input.size());


    stack<int> s;
    //initially
    s.push(-1);

    for(int i= input.size()-1 ; i>=0 ; i--){
        while(s.top()>=input[i]){
            s.pop();
        }
        ans[i]=s.top();
        s.push(input[i]);

    }

    //printing the answer 
    cout<<"output: ";
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }

}

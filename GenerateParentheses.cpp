//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void solve(string &output, vector<string> &ans, int open, int close){
        //base case
        if(open==0 && close==0){
            ans.push_back(output);
        }
        
        //including open bracket
        //1-case solve kardo
        if(open>0){
            output.push_back('(');
            //baki recursion sambhal lega
            solve(output, ans, open-1, close);
            //backtrack
            output.pop_back();
        }
        
        //including close bracket
        //1-case solve kardo
        if(close>0 && close>open){
            output.push_back(')');
            //baki recursion sambhal lega
            solve(output, ans, open, close-1);
            //baktrack
            output.pop_back();
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        string output="";
        vector<string> ans;
        
        int open=n;
        int close=n;
        
        solve(output,ans, open, close);
        
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        
        //inserting all the persons in a stack
        for(int i=0 ; i<n ; i++){
            st.push(i);
        }
        
        //finding out the possible celebrity
        while(st.size() != 1){
            //checking top two persons if anyone of them knows anyone of them
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            //if a knows b
            if(M[a][b]==1){
                //a can't be celebrity, so discard it
                //but b might be celebrity
                st.push(b);
            }
            //if b knows a
            else if(M[b][a]==1){
                //b can't be celebrity, so discard it
                //but might be celebrity
                st.push(a);
            }
            
            
        }
        
        //checking for the one possible person to be celebrity
        int mightBeCelebrity=st.top();
        
        //a celebrity should not know anyone
        for(int i=0 ; i<n ; i++){
            if(M[mightBeCelebrity][i] !=0){
                return -1;
            }
        }
        
        //every person should know the celebrity
        for(int i=0 ; i<n ; i++){
            if(M[i][mightBeCelebrity] ==0 && i != mightBeCelebrity){
                return -1;
            }
        }
        
        return mightBeCelebrity;
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends

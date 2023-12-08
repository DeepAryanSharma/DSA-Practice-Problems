//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    //array to track the frequency of the characters
		    int freq[26]={0};
		    queue<char> q;
		    string ans;
		    
		    for(auto ch:A){
		        //update the frequency
		        freq[ch -'a']++;
		        
		        //push in the queue
		        q.push(ch);
		        
		        //check for first repeating element
		        while(!q.empty()){
		            if(freq[q.front() - 'a']>1){
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        //if the queue gets empty i.e we didn't get any unique char
		        if(q.empty()){
		            ans.push_back('#');a
		        }
		        
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends

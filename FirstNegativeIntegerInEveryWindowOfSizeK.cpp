//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 vector<long long> ans;
                                                 queue<int> q;
                                                 
                                                 //process first window
                                                 for(int i =0 ; i<K ; i++){
                                                     if(A[i]<0){
                                                         q.push(i);
                                                     }
                                                 }
                                                 
                                                 //remaining windows(starting from (k+1)th element)
                                                 for(int i=K ; i<N ; i++){
                                                     //answer dedo purani window ka
                                                     if(q.empty()){
                                                        ans.push_back(0); 
                                                     }
                                                     else{
                                                         ans.push_back(A[q.front()]);
                                                     }
                                                     
                                                     //out of window elements remove kardo
                                                     while(!q.empty() && (i-q.front() >= K)){
                                                         q.pop();
                                                     }
                                                     
                                                     //check current element for insertion
                                                     if(A[i]<0){
                                                         q.push(i);
                                                     } 
                                                 }
                                                 
                                                 //last window ka answer dedo
                                                 if(q.empty()){
                                                        ans.push_back(0); 
                                                     }
                                                     else{
                                                         ans.push_back(A[q.front()]);
                                                 }
                                                 
                                                 
                                                 
                                                 return ans;
                                                 
                                                 
                                                 
 }

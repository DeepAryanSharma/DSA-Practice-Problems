//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int n=q.size();
    int count=k;
    stack<int> st;
    
    //step-1: insert first k element from the queue to stack
    while(count--){
        int element=q.front();
        q.pop();
        st.push(element);
    }
    
    //step-2: insert back the elements from the stack to the queue
    while(!st.empty()){
        int element=st.top();
        st.pop();
        q.push(element);
    }
    
    //step-3: insert the remaining n-k elements from front to rear of the queue
    int rem=n-k;
    while(rem--){
        int element=q.front();
        q.pop();
        q.push(element);
    }
    
    return q;
}

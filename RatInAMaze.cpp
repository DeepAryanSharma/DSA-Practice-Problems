//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool isSafe(vector<vector<int>> &m, vector<vector<bool>> &visited, int row, int col, int x, int y){
        if((x>=row || x<0) || (y>=col || y<0) || (visited[x][y]==true) || m[x][y]==0){
            return false;
        }
        else{
            return true;
        }
        
    }
    
    void mazeSolver(vector<vector<int>> &m, int row, int col,vector<vector<bool>> &visited, string output, vector<string> &paths, int x, int y){
        //basecase
        if(x==row-1 && y==col-1){
            //answer found
            paths.push_back(output);
            return;
        }
        
        //1-case solve kardo
        //Down->(x+1, y)
        if(isSafe(m, visited, row, col, x+1,y)){
            visited[x+1][y]=true;
            //recursive call
            mazeSolver(m, row, col, visited, output+'D', paths, x+1, y);
            
            //backtracking
            visited[x+1][y]=false;
        }
        
        //Up->(x-1,y)
        if(isSafe(m,visited, row, col, x-1,y)){
            visited[x-1][y]=true;
            //recursive call
            mazeSolver(m, row, col, visited, output+'U', paths, x-1, y);
            
            //backtracking
            visited[x-1][y]=false;
        }
        
        //Left->(x,y-1)
        if(isSafe(m,visited, row, col, x,y-1)){
            visited[x][y-1]=true;
            //recursive call
            mazeSolver(m, row, col, visited, output +'L', paths, x, y-1);
            
            //backtracking
            visited[x][y-1]=false;
        }
        
        //Right->(x,y+1)
        if(isSafe(m,visited, row, col, x,y+1)){
            visited[x][y+1]=true;
            //recursive call
            mazeSolver(m, row, col, visited, output +'R', paths, x, y+1);
            
            //backtracking
            visited[x][y+1]=false;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
         //creating string for storing the path
        string output="";
        
        //creating an array to store all the possible paths
        vector<string> paths;
        
        //if source cell is 0
        if(m[0][0]==0){
            return paths;
        }
        int row=n;
        int col=n;
        
        //creating a vector to mark the visited cells
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        visited[0][0]=true;
        //calling the mazeSolver function
        mazeSolver(m, row, col, visited, output, paths, 0, 0);
        
        return paths;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
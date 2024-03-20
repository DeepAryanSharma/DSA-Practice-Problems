class Solution {
public:
    bool isValid(vector<vector<int>> &grid, vector<pair<int, int>>&v){
        int m=grid.size();
        int n=grid[0].size();
        for(auto pt:v){
            if(pt.first<0 || pt.first>=m || pt.second<0 || pt.second>=n ){
                return false;
            }
        }
        return true;
    }
    bool getAllVertices(vector<vector<int>> &grid, int &cx, int cy, int &delta, vector<pair<int, int>> &v){
        pair<int, int> A(cx-delta, cy);
        pair<int, int> B(cx,cy+delta);
        pair<int, int> C(cx+delta, cy);
        pair<int, int> D(cx,cy-delta);

        v[0]=A;
        v[1]=B;
        v[2]=C;
        v[3]=D;

        //check if the curr vertex is valid or not
        if(isValid(grid, v)){
            return true;
        }
        else{
            return false;
        }

        
    }
    void getAllSums(vector<vector<int>> &grid, int &i, int &j, priority_queue<int> &pq){
        //push sums of all rhombus with area 0
        int cx=i;
        int cy=j;
        pq.push(grid[cx][cy]);
        int delta=1;

        //store the vertices of all the possible rhombus from a given center
        vector<pair<int, int>> v(4);
        while(getAllVertices(grid, cx, cy, delta, v)){
            pair<int, int> &A=v[0];
            pair<int, int> &B=v[1];
            pair<int, int> &C=v[2];
            pair<int, int> &D=v[3];

            int csum=0;
            //add areas of all four vertices to the sum
            csum+= grid[A.first][A.second]+grid[B.first][B.second]+grid[C.first][C.second]+grid[D.first][D.second];

            //add the arear of cells in between AB
            for(int i=1 ; i<B.first-A.first ; i++){
                csum+= grid[A.first+i][A.second+i];
            }
            //add the arear of cells in between BC
            for(int i=1 ; i<C.first-B.first ; i++){
                csum+= grid[B.first+i][B.second-i];
            }
            //add the arear of cells in between CD
            for(int i=1 ; i<C.first-D.first ; i++){
                csum+= grid[C.first-i][C.second-i];
            }
            //add the arear of cells in between DA
            for(int i=1 ; i<D.first-A.first ; i++){
                csum+= grid[D.first-i][D.second+i];
            }

            //push the sum in the pq
            pq.push(csum);
            delta++;
        }
    }
    bool canPush(vector<int> &ans, int &sum){
        for(auto s:ans){
            if(s==sum){
                return false;
            }
        }
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int> pq;
        int m=grid.size();
        int n=grid[0].size();
        //get sums for every cell
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                getAllSums(grid, i, j, pq);
            }
        }

        //push the biggest three sums in the ans
        while(!pq.empty() && ans.size()<3){
            int top=pq.top();
            pq.pop();
            if(canPush(ans, top)){
                ans.push_back(top);
            }
        }

        return ans;
        
    }
};

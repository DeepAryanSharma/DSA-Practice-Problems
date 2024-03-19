class compare{
    public:
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        int dist1=a.first*a.first + a.second*a.second;
        int dist2=b.first*b.first + b.second*b.second;
        return dist1 > dist2;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //create a minHeap to store the points according to their distance from the origin
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;

        //push all the points in the minHeap
        for(auto p:points){
            minHeap.push({p[0],p[1]});
        }

        vector<vector<int>> ans;
        //push k closest points in the ans
        while(k--){
            pair<int, int> temp=minHeap.top();
            minHeap.pop();
            ans.push_back({temp.first, temp.second});
        }

        return ans;
        
    }
};

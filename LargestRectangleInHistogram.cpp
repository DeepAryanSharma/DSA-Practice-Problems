class Solution {
public:
    vector<int> nextSmaller(vector<int> &heights){
        vector<int> next(heights.size());
        stack<int> s;
        s.push(-1);

        for(int i=heights.size()-1 ; i>=0 ; i--){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){ //checking for not equal to -1 coz, index should alway be a valid index
                s.pop();
            }
            //if smaller is found
            next[i]=s.top();
            s.push(i);
        }
        return next;
    }
    vector<int> prevSmaller(vector<int> &heights){
        vector<int> prev(heights.size());
        stack<int> s;
        s.push(-1);

        for(int i=0 ; i<heights.size() ; i++){
            while(s.top()!=-1 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            //if smaller is found
            prev[i]=s.top();
            s.push(i);
            
        }

        return prev;

    }
    int largestRectangleArea(vector<int>& heights) {
        //step1: prevSmaller length
        vector<int> prev=prevSmaller(heights);
        //step2: nextSmaller length
        vector<int> next=nextSmaller(heights);

        int maxArea=INT_MIN;

        for(int i=0 ; i<heights.size() ; i++){
            if(next[i]==-1){
                next[i]=heights.size();
            }
            int length=heights[i];
            int width=next[i]-prev[i]-1;
            int area=width*length;

            maxArea=max(maxArea, area);
        }

        return maxArea;
        
    }
};

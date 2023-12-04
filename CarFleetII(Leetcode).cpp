class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(), -1);//collisiion  time of ith car with next car
        stack<int>st;
        for(int i=cars.size()-1 ; i>=0 ; i--){
            //avoid the ahead cars which are faster than the current car
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]){
                st.pop();
            }

            //ahead cars which are slower than the current car
            while(!st.empty()){
                double colTime=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ans[st.top()]==-1 || colTime<=ans[st.top()]){
                    ans[i]=colTime;
                    break;
                }
                else{
                    st.pop();
                }
            } 
            st.push(i);
        }
        return ans;
        
    }
};

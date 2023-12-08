class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;

        //process first window
        for(int i=0 ; i<k ; i++){
            //chote element ko remove kardo
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();

            }

            //inserting current element, so that checkout of window element
            dq.push_back(i);
            
        }

        //current window ka answer store kardo
        ans.push_back(nums[dq.front()]);

        //process the remaining windows
        for(int i=k ; i<nums.size() ; i++){
            //remove the out of window element
            if(!dq.empty() && (i-dq.front() >= k)){
                dq.pop_front();
            }

             //chote element ko remove kardo
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();

            }

            //inserting current element, so that checkout of window element
            dq.push_back(i);

            //current window ka answer store kardo
            ans.push_back(nums[dq.front()]);
   
        }

        return ans;
        
    }
};

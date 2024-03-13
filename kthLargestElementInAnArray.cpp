class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Step-1: create a min-heap
        priority_queue<int, vector<int>, greater<int>> pq;

        //Step-2: insert first k elements in the min-heap
        for(int i=0 ; i<k ; i++){
            pq.push(nums[i]);
        }

        //Step-3: insert the rest of the elements only when the current element is greater than the top element
        for(int i=k ; i<nums.size() ; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        //now the topmost element of the min-heap is the kth greatest element
        return pq.top();

        
    }
};

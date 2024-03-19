class Solution {
public:
#define ll long long
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        vector<ll> prefixSum(nums.size(), -1);//prefixSum[i]: min possible sum on n elements upto ith index from the start
        vector<ll> suffixSum(nums.size(), -1);//suffixSum[i]: max possible sum of n elements upto ith index from the end

        //for prefixSum
        priority_queue<ll> maxHeap; //maxHeap
        ll sum=0;
        for(int i=0 ; i<nums.size() ; i++){
            //include the curr in the sum and the maxheap
            sum+=nums[i];
            maxHeap.push(nums[i]);

            //if the size of maxHeap becomes greator than n then pop the top element(i.e. max element)
            if(maxHeap.size() > n){
                ll top=maxHeap.top();
                maxHeap.pop();
                sum -= top;      
            }

            //if the size of maxHeap becomes equal to then include the sum 
            if(maxHeap.size()==n){
                prefixSum[i]=sum;
            }
        }

        //for suffixSum
        priority_queue<ll, vector<ll>, greater<ll>> minHeap; //minHeap
        sum=0;
        for(int i=nums.size()-1 ; i>=0 ; i--){
            //include the curr in the sum and the maxheap
            sum+=nums[i];
            minHeap.push(nums[i]);

            //if the size of maxHeap becomes greator than n then pop the top element(i.e. max element)
            if(minHeap.size() > n){
                ll top=minHeap.top();
                minHeap.pop();
                sum -= top;      
            }

            //if the size of maxHeap becomes equal to then include the sum 
            if(minHeap.size()==n){
                suffixSum[i]=sum;
            }
        }

        ll ans= LONG_LONG_MAX;
        for(int i=n-1 ; i<2*n ; i++){
            ans=min(ans, prefixSum[i]-suffixSum[i+1]);
        }

        return ans;
        
    }
};

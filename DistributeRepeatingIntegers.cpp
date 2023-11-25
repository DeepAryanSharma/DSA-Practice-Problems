class Solution {
public:
    bool canDistributeHelper(vector<int> &quantity, vector<int> &counts, int ithCustomer){
        //base case
        if(ithCustomer>=quantity.size()){
            return true;
        }

        for(int i=0; i<counts.size() ; i++){
            if(counts[i]>=quantity[ithCustomer]){
                counts[i]=counts[i]-quantity[ithCustomer];
                if(canDistributeHelper(quantity, counts, ithCustomer+1)){
                    return true;
                }
                //backtrack
                counts[i]=counts[i]+quantity[ithCustomer];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> countMap;
        for(auto num : nums){
            countMap[num]++;
        }
        vector<int> counts;
        for(auto it:countMap){
            counts.push_back(it.second);
        }
        sort(quantity.rbegin(), quantity.rend());//sorting in decreasing order , to overcome the TLE
        int ithCustomer=0;
        return canDistributeHelper(quantity, counts, ithCustomer);

        
    }
};

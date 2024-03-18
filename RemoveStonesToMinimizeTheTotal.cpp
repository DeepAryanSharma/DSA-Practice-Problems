class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        //create maxHeap
        priority_queue<int> maxHeap;

        //insert elements of the given array in the maxheap
        for(int i=0 ; i<piles.size() ; i++){
            maxHeap.push(piles[i]);
        }

        //performing k operations
        while(k--){
            int maxElement=maxHeap.top();
            maxHeap.pop();
            maxElement=maxElement-floor(maxElement/2);
            maxHeap.push(maxElement);
        }

        //calculate the sum of the remaining stones
        int sum=0;
        for(int i=0 ; i<piles.size() ; i++){
            int stones=maxHeap.top();
            maxHeap.pop();
            sum+=stones;
        }

        return sum;
        
    }
};

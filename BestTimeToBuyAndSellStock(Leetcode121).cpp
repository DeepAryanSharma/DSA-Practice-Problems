class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int least_price=INT_MAX;
        int current_profit=0;

        for(int i=0; i<prices.size() ; i++){
            if(prices[i]<least_price){
                least_price=prices[i];
            }
            current_profit=prices[i]-least_price;
            if(current_profit>max_profit){
                max_profit=current_profit;
            }
        }
        return max_profit;
        
    }
};
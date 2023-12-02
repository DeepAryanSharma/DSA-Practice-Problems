class StockSpanner {
public:
    stack<pair<int,int>> stock;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!stock.empty() && stock.top().first<=price){
            span +=stock.top().second;
            stock.pop();
        }
        stock.push({price,span});

        return span;        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

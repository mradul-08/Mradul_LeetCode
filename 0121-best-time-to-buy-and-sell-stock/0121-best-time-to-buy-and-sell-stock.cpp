class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int best_buy = prices[0];
        int max_profit = 0;

        for(int i = 0; i < n; i++){
        if(prices[i] > best_buy){
        
            max_profit = max( max_profit,prices[i] - best_buy );

            
        }
    best_buy = min(prices[i], best_buy);
        } 
        return max_profit;
    }
};
class Solution {
public:
    vector<vector<int>> dp;

    int maxP(vector<int>& prices, int day, int n,
             int buy, int fee) {

        if(day >= n)
            return 0;

        if(dp[day][buy] != -1)
            return dp[day][buy];

        if(buy) {
            int take = maxP(prices, day+1, n, 0, fee)
                       - prices[day];

            int skip = maxP(prices, day+1, n, 1, fee);

            return dp[day][buy] = max(take, skip);
        }

        int sell = maxP(prices, day+1, n, 1, fee)
                   + prices[day] - fee;

        int skip = maxP(prices, day+1, n, 0, fee);

        return dp[day][buy] = max(sell, skip);
    }

    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();

        dp.assign(n, vector<int>(2, -1));

        return maxP(prices, 0, n, 1, fee);
    }
};
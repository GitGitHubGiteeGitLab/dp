/**
* dp[i]表示在第i天结束之后所能获得的最大利润
* 买入 可交易
* 可交易->买入 , 买入->买入(买了不卖，仍然是买入)
* 买入->可交易, 可交易->交易
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = -prices[0];
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i] - fee);
        }
        //dp[n-1][0] 一定小于 dp[n-1][0]
        return dp[n-1][1];
    }
};
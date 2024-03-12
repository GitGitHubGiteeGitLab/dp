/**
* 重点是结束后
* dp[i][0]表示：第i天结束后，处于"买入"状态，此时的最大利润
* dp[i][1]表示：第i天结束后， 处于"可交易(可买入)"状态，此时的最大利润
* dp[i][2]表示：第i天结束后, 处于"冷冻期"状态，此时的最大利润
* 买入->买入 可交易->买入  
* 冷冻期->可交易 可交易->可交易
* 买入->冷冻期 
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3));
        dp[0][0] = -prices[0]; //dp[0][1] = 0没买入 dp[0][2] = 0当天买入又卖出
        for(int i = 1;i < n; i++){
           dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]); 
           dp[i][1] = max(dp[i-1][1], dp[i-1][2]);
           dp[i][2] = dp[i-1][0] + prices[i];//当天结束处于cooldown，就要今天出手
        }
        //return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
        //dp[n-1][0]不用考虑,买入没出手必然小于另外两个
        return max(dp[n-1][1], dp[n-1][2]);
    }
};
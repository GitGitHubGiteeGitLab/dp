/**
    dp[i][0]表示：粉刷到i位置的时候，最后一个位置粉刷上红色，此时的最小花费
    dp[i][1],dp[i][2]和dp[i][0]类似
    dp[i][0] = min(dp[i][1], dp[i][2]) + costs[i][0];
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        size_t n = costs.size();
        //vector<vector<int>> dp(n, vector<int>(3));
        //dp[0][0] = costs[0][0];
        //dp[0][1] = costs[0][1];
        //dp[0][2] = costs[0][2];
        //for(int i = 1; i < n; i++){
        //    dp[i][0] += min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
        //    dp[i][1] += min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
        //    dp[i][2] += min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        //}
        //return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
        vector<vector<int>> dp(n+1, vector<int>(3));
        for(int i = 1; i <= n; i++){
            dp[i][0] += min(dp[i-1][1], dp[i-1][2]) + costs[i-1][0];
            dp[i][1] += min(dp[i-1][0], dp[i-1][2]) + costs[i-1][1];
            dp[i][2] += min(dp[i-1][0], dp[i-1][1]) + costs[i-1][2];
        }
        return min(dp[n][0], min(dp[n][1], dp[n][2]));
    }
};
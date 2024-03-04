/**
    dp[i][j]表示: 到达[i, j]位置的时候，此时的最大价值
    dp[i][j] = frame[i-1][j-1] + max(dp[i-1][j], dp[i][j-1]); 
*/
class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size();
        int n = frame[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
               dp[i][j] = frame[i-1][j-1] + max(dp[i-1][j], dp[i][j-1]); 
            }
        } 
        return dp[m][n];
    }
};
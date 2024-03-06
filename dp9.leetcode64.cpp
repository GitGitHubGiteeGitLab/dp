/**
    初始化dp表的时候要全填为INT_MAX,保证后续dp表填充正确
    第二步要修正dp[0][1] = 0,保证dp[1][1]填表正确
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][1] = 0; 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
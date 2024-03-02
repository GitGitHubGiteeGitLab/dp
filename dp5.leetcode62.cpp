class Solution {
public:
    int uniquePaths(int m, int n) {
        //以i, j为结尾 dp[i][j]表示: 走到[i, j]位置的守，一共有多少种方式
        //状态转移方程 dp[i][j] = dp[i][j-1] + dp[i-1][j]，为什么不是dp[i][j-1]+1+dp[i-1][j]+1多了一步而非一种方法
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        //初始化
        dp[0][1] = 1;
        //注意映射关系
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        return dp[m][n];
    }
};
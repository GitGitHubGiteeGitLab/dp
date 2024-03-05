/**
    n + 1行， n + 2列, reason i-1 j-1,j,j+1
    第0行初始化为0，是因为dp[1][j]计算时dp[i-1][j-1] dp[i-1][j] dp[i-1][j+1]必须都为0
    为什么其余初始化为INT_MAX(+无穷大)，reason: dp[2][1]计算时，dp[1][0]为0,dp[1][0]就是最小，这是不对的，dp[1][0]得是正无穷,dp[1][0] =  INT_MAX
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, INT_MAX));
        for(auto& e : dp[0])e = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]) ) + matrix[i-1][j-1];
            }
        }
        int minNum = INT_MAX;
        for(int i = 1; i <= n; i++){
            minNum = min(minNum, dp[n][i]);
        }
        return minNum;
    }
};
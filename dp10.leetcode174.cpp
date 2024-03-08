/**
*本题的思路是：骑士说，公主...我过不去...；公主说，王子...你等着，我来找你...
* dp[i][j]表示： 从起点出发，到达[i, j]位置的时候，所需要的最低初始健康点数
*   上面这一表示方法的错误之处在于dp[i][j]不仅受到上边和左边的影响，还有可能受到右边和下边的影响
*   所以以某个位置为结尾，不可以，因为有后效性
*   我们换一种方式表示，以某个位置为起点
*   dp[i][j]表示：从[i, j]位置出发，到达终点，所需的最低初始健康点数
*   状态转移方程 x = dp[i][j], x + dungeon[i][j] >= dp[i][j+1]->x >= dp[i][j + 1] - dungeon[i][j]  x + dungeon[i][j] >= dp[i+1][j], dp[i][j] = max(1, dp[i][j])防止dp[i][j]是负数，也就是血包值过大的情况(血包过大，后面减血无需担心，因为血量是够的，所以可以更新为1)
*下边加一行，右边加一行
*骑士至少得剩1滴血
*填表顺序从下往上，从右往左填表
*dp[0][0]
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n-1] = dp[m-1][n] = 1;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                dp[i][j] =  min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = max(1, dp[i][j]); 
            }
        }
        return dp[0][0];

    }
};
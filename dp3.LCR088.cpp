/*
    dp[i]表示到达第i个台阶的最小花费。
		记住可以从0号台阶或1号台阶出发
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t sz = cost.size();
        if(sz == 2)return min(cost[0], cost[1]);
				//创建dp表
        vector<int> dp(sz);
				//初始化
        dp[1] = 0;
        dp[2] = min(cost[0], cost[1]);
        
				//填表
				for(int i = 3; i < sz; i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
				//返回结果
        return min(dp[sz-1] + cost[sz-1], dp[sz-2] + cost[sz-2]);
    }
};

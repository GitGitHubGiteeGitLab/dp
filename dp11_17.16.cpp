/**
* a.状态表示和状态转移方程
* dp[i]表示 选到i位置的时候，此时的最长预约时长
* f[i]表示: 选择到i位置的时候，nums[i]必选，此时的最长预约时长
* g[i]表示:选择到i位置的时候，nums[i]不选，此时的预约时长
* f[i] = g[i - 1] + nums[i]
* g[i] = max(f[i - 1], g[i - 1])
*
* b.初始化
* f[0] = nums[0] g[0] = 0;

* c.填表顺序
* 从左往右，两个表一起选
*
* d.返回值
* max(f[n-1], g[n-1]) 
*/
class Solution {
public:
    int massage(vector<int>& nums) {
        size_t n = nums.size();
        if(n == 0)
            return 0;
        
        vector<int> f(n), g(n);
        f[0] = nums[0];
        for(int i = 1; i < n; i++){
            f[i] = g[i-1] + nums[i];
            g[i] = max(g[i-1], f[i-1]);
        }
        return max(f[n-1], g[n-1]);
    }
};

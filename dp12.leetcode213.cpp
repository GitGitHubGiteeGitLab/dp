class Solution {
public:
    int rob(vector<int>& nums) {
       int n = nums.size(); 
       //返回两种情况的最大值
       //选0不能选1
       return max(nums[0] + __rob(nums, 2, n - 2), __rob(nums, 1, n - 1));
    }
    
    int __rob(vector<int>& nums, int l, int r){
        //if(l >= r)return 0;会把l == r的情况漏掉
        if(l > r)return 0;
        
        vector<int> g(nums.size()), f(g);
        g[l] = 0; f[l] = nums[l];
        for(int i = l + 1; i <= r; ++i){
            f[i] = g[i - 1] + nums[i];
            g[i] = max(f[i - 1] ,g[i - 1]);
        }
        return max(f[r], g[r]);
    }
};

/**
*   
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        enum{N = 10001};
        int arr[N] = {0};
        for(auto e : nums) arr[e] += e;
        vector<int> f(N), g(f);
        //保证相邻的不会选上
        for(int i = 1; i < N; i++){
            f[i] = g[i-1] + arr[i];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(f[N - 1], g[N - 1]);
    }
};
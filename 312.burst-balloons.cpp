/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#define MAX 301
int dp[MAX][MAX];
class Solution {
public:
    int solve(vector<int>& a, int idx, int jdx)
    {
        if(idx == jdx) return a[idx];
        if(jdx-idx+1 == 2) return a[idx] * a[jdx]; 
        if(dp[idx][jdx] != -1) return dp[idx][jdx];

        int i{}, j{};
        int ans{};
        for(i = idx; i <= jdx-1; i++)
        {
            for(j = i+1; j <= jdx-1; j++)
            {
                int res = solve(a, idx, i) + solve(a, i+1, j) + solve(a, j+1, jdx);
                cout << idx << " " << i << " " << j << " " << jdx << " " << res << endl;
                ans = max(res, ans);
            }
        }
        return dp[idx][jdx] = ans;
    }

    int maxCoins(vector<int>& a) {
        int i{}, j{}, k{}, n{int(a.size())};
        memset(dp, -1, sizeof(dp));
        return solve(a, 0, n-1);
    }
};
// @lc code=end


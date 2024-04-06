/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
bool dp[22][22];
class Solution {
public:
    bool isMatch(string s, string p) {
        int n{int(s.length())}, m{int(p.length())}, i{}, j{};
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(i = 2; i <= m; i++)
        {
            if(p[i-1] == '*') dp[i][0] = dp[i-2][0];
        }
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(p[i-1] == '.')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*')
                {
                    if(p[i-2] == s[j-1] || p[i-2] == '.') dp[i][j] = dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
                    dp[i][j] |= dp[i-2][j];
                }
                else
                {
                    if(p[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int i{}, j{}, n{int(s.length())}, m{int(p.length())};
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (i = 1; i <= m; i++)
        {
            if (p[i - 1] != '*')
                break;
            else
                dp[i][0] = true;
        }

        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                if (p[i - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

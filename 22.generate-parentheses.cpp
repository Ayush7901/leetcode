/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    void solve(string& s, int n1, int n2, vector<string>& ans)
    {
        if(n1 == 0 && n2 == 0)
        {
            ans.push_back(s);
            return;
        }
        if(n1)
        {
            s.push_back('(');
            solve(s, n1-1, n2, ans);
            s.pop_back();
        }
        if(n2 > n1)
        {
            s.push_back(')');
            solve(s, n1, n2-1, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(s, n, n, ans);
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
unordered_map<char, string> digToChar = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};
class Solution {
public:
    void solve(string& s, string& c, int idx, vector<string>& ans)
    {
        if(idx == s.length())
        {
            ans.push_back(c);
            return;
        }
        for(auto& ch : digToChar[s[idx]])
        {
            c.push_back(ch);
            solve(s, c, idx+1, ans);
            c.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string res;
        solve(digits, res, 0, ans);
        return ans;
    }
};
// @lc code=end


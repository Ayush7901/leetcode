/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
vector<string> ans;
class Solution
{
public:
    string createSentence(vector<string> &w)
    {
        int i{}, n{int(w.size())};
        string ans;
        for (i = 0; i < n; i++)
        {
            ans.append(w[i]);
            if (i != n - 1)
                ans.push_back(' ');
        }
        return ans;
    }

    void solve(string &s, unordered_set<string> &dict, int idx, vector<string> &c)
    {
        if (idx == s.length())
        {
            ans.push_back(createSentence(c));
            return;
        }
        for (int i = idx; i < s.length(); i++)
        {
            string part = s.substr(idx, i - idx + 1);
            if (dict.find(part) != dict.end())
            {
                c.push_back(part);
                solve(s, dict, i + 1, c);
                c.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int i{}, l{int(s.length())};
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        ans.clear();
        vector<string> w;
        solve(s, dict, 0, w);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

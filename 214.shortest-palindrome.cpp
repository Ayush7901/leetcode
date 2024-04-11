/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        int i{}, l{int(s.length())}, len{};
        string r = s;
        reverse(r.begin(), r.end());
        string p = s + '#' + r;
        int n{int(p.length())};
        vector<int> lps(n, 0);
        len = 0, i = 1;
        while(i < n)
        {
            if(p[i] == p[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0) i++;
                else len = lps[len-1];
            }
        }
        // for(i = 0; i < n; i++)
        // {
        //     cout << lps[i] << ' ';
        // }
        string part = (l - lps[n-1]) ? r.substr(0, l - lps[n-1]) : "";
        part += s;
        return part;
    }
};
// @lc code=end


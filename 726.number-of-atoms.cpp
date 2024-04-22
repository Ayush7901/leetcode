/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 */

// @lc code=start
class Solution {
public:
    bool isDigit(char c) { return c >= '0' && c <= '9'; }
    bool isUpperCase(char c) { return c >= 'A' && c <= 'Z'; }
    bool isLowerCase(char c) { return c >= 'a' && c <= 'z'; }

    void parser(string& s, int multi, map<string, int>& res)
    {
        map<string, int> temp;
        int i{}, l{int(s.length())};
        while(i < l)
        {
            string symbol;
            if(isUpperCase(s[i]))
            {
                symbol = s[i];
                i++;
                if((i < l && isUpperCase(s[i])) || (i >= l))
                {
                    temp[symbol] = 1;
                    continue;
                }
                if(i < l && isLowerCase(s[i]))
                {
                    symbol += s[i];
                    i++;
                }
                if(i < l && isDigit(s[i]))
                {
                    string num;
                    int k{i};
                    while(i < l && isDigit(s[i])) i++;
                    int cnt = stoi(s.substr(i, k - i));
                    temp[symbol] = cnt;
                }

            }
            
        }
        for(auto& val : temp)
        {
            res[val.first] += val.second * multi;
        }
    }

    string countOfAtoms(string formula) {
        map<string, int> atoms;
        vector<string> part;
        stack<char> st;

        int i{}, l{int(s.length())};
        for(i = 0; i < l; i++)
        {
            
        }

    }
};
// @lc code=end


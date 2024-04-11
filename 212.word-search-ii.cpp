/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
bool vis[13][13];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution
{
public:
    inline bool isAllowed(int n, int m, int x, int y)
    {
        return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
    }

    bool dfs(vector<vector<char>> &a, string &w, int x, int y, int idx)
    {
        int l{int(w.length())}, n{int(a.size())}, m{int(a[0].size())};
        if (idx == l)
            return true;
        bool found = false;
        vis[x][y] = true;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if ((nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) && (w[idx] == a[nx][ny]))
            {
                found |= dfs(a, w, nx, ny, idx + 1);
                // vis[nx][ny] = true;
            }
        }
        vis[x][y] = false;
        return found;
    }

    vector<string> findWords(vector<vector<char>> &a, vector<string> &words)
    {
        int i{}, j{}, n{int(a.size())}, m{int(a[0].size())}, sz{int(words.size())};
        memset(vis, 0, sizeof(vis));
        unordered_set<string> res;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    if (res.find(words[k]) != res.end())
                    {
                        continue;
                    }
                    if (a[i][j] == words[k][0])
                    {

                        bool found = dfs(a, words[k], i, j, 1);
                        if (found)
                        {
                            res.insert(words[k]);
                        }
                    }
                }
            }
        }
        vector<string> ans(res.begin(), res.end());
        // sort(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=719 lang=cpp
 *
 * [719] Find K-th Smallest Pair Distance
 */

// @lc code=start

auto comp = [](vector<int>& a, vector<int>& b)
{
    return a[0] > b[0];
};

class Solution {
public:
    int smallestDistancePair(vector<int>& a, int k) {
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        int i{}, j{}, n{int(a.size())};
        unordered_set<pair<int, int>> st;

        sort(a.begin(), a.end());
        
    }
};
// @lc code=end


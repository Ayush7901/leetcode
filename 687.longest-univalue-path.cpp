/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define MIN -1005
typedef TreeNode node;
class Solution {
public:
    int solve(node* root, int& res)
    {
        if(!root) return 0;
        int L = solve(root->left, res);
        int R = solve(root->right, res);

        int temp = 0, poss = 0;

        if(root->left && root->left->val == root->val) 
        {
            temp += (L+1);
            L++;
            poss = L;
        }
        if(root->right && root->right->val == root->val) 
        {
            temp += (R+1);

            R++;
            poss = max(poss, R);
        }


        res = max({res, temp, L, R});
        return poss;
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};
// @lc code=end


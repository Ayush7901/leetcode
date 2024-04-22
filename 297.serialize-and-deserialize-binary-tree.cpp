/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define SEP (',')
#define NULLPTR (-1001)
#define NULLPTRSTR ("-1001")
typedef TreeNode node;
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        std::string s;
        // std::vector<TreeNode *> par;
        queue<node *> q;
        if (!root)
            return s;
        q.push(root);
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (!p)
            {
                s += NULLPTRSTR;
                s += SEP;
                continue;
            }
            s += to_string(p->val);
            s += SEP;
            q.push(p->left);

            q.push(p->right);
        }

        s.pop_back();
        cout << s << "\n";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string s)
    {
        TreeNode *root = nullptr;
        if (s.length() == 0)
            return root;
        int i{}, l{int(s.length())};
        vector<int> data;
        for (i = 0; i < l; i++)
        {
            int j{i};
            while (j < l && s[j] != SEP)
                j++;
            int val = stoi(s.substr(i, j - i));
            i = j;
            data.push_back(val);
        }
        // cout << "SIZE: " << data.size() << "\n";
        root = new TreeNode(data[0]);
        int j = 1;
        // TreeNode *curr = root;
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto p = q.front();
                q.pop();
                if(data[j] == NULLPTR)
                {
                    p->left = nullptr;
                    j++;
                }
                else
                {
                    node *curr = new node(data[j]);
                    p->left = curr;
                    q.push(curr);
                    j++;
                }

                if(data[j] == NULLPTR)
                {
                    p->right = nullptr;
                    j++;
                }
                else
                {
                    node *curr = new node(data[j]);
                    p->right = curr;
                    q.push(curr);
                    j++;
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

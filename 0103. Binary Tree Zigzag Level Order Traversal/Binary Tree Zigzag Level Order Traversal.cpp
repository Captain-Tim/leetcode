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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> qu;
        bool from_left = true;
        vector<vector<int>> res;
        qu.push(root);
        while (!qu.empty())
        {
            res.push_back({});
            for (int i = 0, n = qu.size(); i < n; ++i)
            {
                root = qu.front();
                qu.pop();
                res.back().push_back(root->val);
                if (root->left) qu.push(root->left);
                if (root->right) qu.push(root->right);
            }
            if (!from_left)
                reverse(res.back().begin(), res.back().end());
            from_left = !from_left;
        }
        return res;
    }
};
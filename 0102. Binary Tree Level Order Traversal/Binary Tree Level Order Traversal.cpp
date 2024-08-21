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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        queue<TreeNode*> qu;
        qu.push(root);
        vector<vector<int>> res;
        while (!qu.empty())
        {
            vector<int> cur_level(qu.size());
            for (int i = 0, n = qu.size(); i < n; ++i)
            {
                root = qu.front();
                qu.pop();
                cur_level[i] = root->val;
                if (root->left)
                    qu.push(root->left);
                if (root->right)
                    qu.push(root->right);
            }
            res.push_back(cur_level);
        }
        return res;
    }
};
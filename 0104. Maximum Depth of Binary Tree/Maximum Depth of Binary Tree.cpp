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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int res = 0;
        while (!qu.empty())
        {
            for (int i = 0, n = qu.size(); i < n; ++i)
            {
                root = qu.front();
                qu.pop();
                if (root->left)
                    qu.push(root->left);
                if (root->right)
                    qu.push(root->right);
            }
            ++res;
        }
        return res;
    }
};
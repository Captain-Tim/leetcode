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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int& res)
    {
        if (!root)
            return 0;
        int left_height = helper(root->left, res);
        int right_height = helper(root->right, res);
        res = max(res, left_height + right_height);
        return max(left_height, right_height) + 1;
    }
};
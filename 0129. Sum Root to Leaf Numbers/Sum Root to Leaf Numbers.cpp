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
    int sumNumbers(TreeNode* root) {
        stack<TreeNode*> stk;
        int cur_val = 0;
        int res = 0;
        
        while (root || !stk.empty())
        {
            while (root)
            {
                cur_val *= 10;
                cur_val += root->val;
                stk.push(root);
                root = root->left ? root->left : root->right;
            }
            root = stk.top();
            stk.pop();
            if (!root->left && !root->right)
                res += cur_val;
            cur_val /= 10;
            
            if (!stk.empty() && stk.top()->left == root)
                root = stk.top()->right;
            else
                root = nullptr;
        }
        return res;
    }
};
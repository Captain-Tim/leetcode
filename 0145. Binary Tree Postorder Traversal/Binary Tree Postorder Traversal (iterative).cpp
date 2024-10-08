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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        while (root || !stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left ? root->left : root->right;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            if (!stk.empty() && stk.top()->left == root)
                root = stk.top()->right;
            else
                root = nullptr;
        }
        
        return res;
    }
};
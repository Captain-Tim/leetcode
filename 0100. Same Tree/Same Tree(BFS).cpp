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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);
        while (!qu.empty())
        {
            p = qu.front();
            qu.pop();
            q = qu.front();
            qu.pop();
            if (!p && !q)
                continue;
            else if ( (!p || !q) || (p->val != q->val) )
                return false;
            qu.push(p->left);
            qu.push(q->left);
            qu.push(p->right);
            qu.push(q->right);
        }
        return true;
    }
};
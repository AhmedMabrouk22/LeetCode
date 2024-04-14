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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        
        if (root -> left)
        {
            if (!root->left->left && !root->left->right)
                res += root->left->val;
            else 
                res += sumOfLeftLeaves(root->left);
        }
        
        if (root -> right) 
            res += sumOfLeftLeaves(root->right);
        
        return res;
        
    }
};
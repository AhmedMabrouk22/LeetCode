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
    
    int solve(TreeNode* node,int val)
    {
        if (!node -> left && !node -> right)
            return (val * 10) + node -> val;
        
        int res = 0;
        if (node -> left)
            res += solve(node -> left, (val * 10) + node -> val);
        if (node -> right)
            res += solve(node -> right, (val * 10) + node -> val);
        return res;
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};
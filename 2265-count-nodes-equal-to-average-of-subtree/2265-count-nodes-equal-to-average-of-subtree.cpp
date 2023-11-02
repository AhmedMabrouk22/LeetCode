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
    int res = 0;
    pair<int,int>solve(TreeNode* node)
    {
        if(!node) return {0,0};
        
        auto l = solve(node->left);
        auto r = solve(node->right);
        
        int sum = l.first + r.first + node->val;
        int cnt  = l.second + r.second + 1;
        
        if (node->val == sum / cnt)\
            ++res;
        return {sum,cnt};
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};
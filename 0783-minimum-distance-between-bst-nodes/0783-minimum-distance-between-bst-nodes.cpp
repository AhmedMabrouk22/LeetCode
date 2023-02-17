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

    vector<int>v;
    void solve(TreeNode* root)
    {
        if (!root)
            return;
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        int res = 1e6;
        solve(root);
        for(int i = 0 ; i < v.size() -1 ; ++i)
            res = min(res,v[i+1] - v[i]);
        return res;
    }

    
};
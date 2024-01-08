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
    void dfs(TreeNode* node) 
    {
        if (!node)
            return;
        
        if (node->left)
            dfs(node->left);
        
        v.push_back(node->val);
        if (node->right)
            dfs(node->right);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root);
        int sum = 0;
        for(auto i : v)
        {
            if (i >= low && i <= high) sum += i;
        }
        return sum;
    }
};
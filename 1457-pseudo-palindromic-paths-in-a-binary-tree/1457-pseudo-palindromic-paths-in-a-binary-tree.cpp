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
    int odd = 0;
    int even = 0;
    int res = 0;
    
    int dfs(TreeNode* node, vector<int>&frq)
    {
       
        
        if (!node) return 0;
        
        ++frq[node -> val];
        
        if (!node->left && !node -> right)
        {
            int cnt = 0;
            for(auto i : frq)
            {
                if (i % 2 != 0) ++cnt;
            }
            
            --frq[node -> val];
            
            if (cnt <= 1) return 1;
            else return 0;
        }
        
        
        int l = dfs(node -> left,frq);        
        int r = dfs(node -> right,frq);
        
       --frq[node -> val];
        
        return l + r;
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>frq(10,0);
        return dfs(root,frq);
    }
};
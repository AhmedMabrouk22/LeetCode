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
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        map<int,int>frq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) 
        {
            auto cur = q.front();
            q.pop();
            ++frq[cur->val];

            if (cur->left) 
                q.push(cur->left);
            
            if (cur->right) 
                q.push(cur->right);
        }
        int mx = 0;
        for(auto i : frq)
            mx = max(mx,i.second);
        for(auto i : frq)
        {
            if(i.second == mx) 
                res.push_back(i.first);
        }
        
        return res;
    }
};
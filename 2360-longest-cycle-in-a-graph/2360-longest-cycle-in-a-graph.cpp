class Solution {
public:
    vector<bool>vis;
    int res = -1;
    void dfs(int node,vector<int>& edges,unordered_map<int,int>& mp) 
    {
        vis[node] = true;
        int child = edges[node];
        if (child != -1 && !vis[child])
        {
            mp[child] = mp[node] + 1;
            dfs(child,edges,mp);

        }
        else if (child != -1 && mp.count(child)) 
            res = max(res,mp[node] - mp[child] + 1);
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vis = vector<bool>(n);
        for(int i = 0 ; i < n ; ++i)
        {
            if(!vis[i])
            {
                unordered_map<int,int>mp;
                mp[i] = 1;
                dfs(i,edges,mp);
            }
        }
        return res;
    }
};
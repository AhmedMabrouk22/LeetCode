class Solution {
public:
    vector<vector<int>>graph;
    vector<bool>vis;
    int cnt;
    void dfs(int u)
    {
        vis[u] = true;
        for(auto child : graph[u])
        {
            if (!vis[child])
                dfs(child);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n -1 )
            return -1;
        graph = vector<vector<int>>(n);
        vis = vector<bool>(n);
        for(auto i : connections)
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        for(int i = 0 ; i < n ; ++i) 
        {
            if (!vis[i])
            {
                dfs(i);
                ++cnt;
            }
        }
        
        return cnt - 1;
    }
};
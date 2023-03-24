class Solution {
public:
    vector<vector<pair<int,bool>>>graph;
    vector<bool>vis;
    int res;
    void dfs(int u)
    {
        vis[u] = true;
        for(auto child : graph[u]) 
        {
            if (!vis[child.first])
            {
                if (child.second)
                    ++res;
                dfs(child.first);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        graph = vector<vector<pair<int,bool>>>(n);
        vis = vector<bool>(n);

        for(auto i : connections) 
        {
            graph[i[0]].push_back({i[1],true});
            graph[i[1]].push_back({i[0],false});
        }
        dfs(0);
        return res;
    }
};
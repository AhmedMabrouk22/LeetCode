class Solution {
public:
    vector<vector<int>>graph;
    vector<bool>vis;
    int dfs(int u) 
    {
        vis[u] = true;
        int cnt = 0;
        for(auto child : graph[u])
        {
            if (!vis[child])
                cnt += dfs(child) + 1;
        }
        return cnt;
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n);
        vis = vector<bool>(n);

        for(auto i : edges) 
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        vector<int>v;
        for(int i = 0 ; i < n ; ++i)
        {
            if (!vis[i])
                v.push_back(dfs(i) + 1);
        }

        long long res = 0;
        long long sum = v[0];
        for(int i = 1 ; i < v.size(); ++i) 
        {
            res += sum*v[i];
            sum += v[i];
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<pair<int,int>>>graph;
    vector<bool>vis;

    int bfs() 
    {
        queue<int>q;
        int res = INT_MAX;
        q.push(1);
        vis[1] = true;
        while(!q.empty()) 
        {
            int cur = q.front();
            q.pop();
            for(auto child : graph[cur]) 
            {
                res = min(res,child.second);
                if (!vis[child.first])
                {
                    q.push(child.first);
                    vis[child.first] = true;
                }
            }
        }
        return res;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        graph = vector<vector<pair<int,int>>>(n+1);
        vis = vector<bool>(n+1);
        for(auto i : roads) {
            graph[i[0]].push_back({i[1],i[2]});
            graph[i[1]].push_back({i[0],i[2]});
        }

        return bfs();
    }
};
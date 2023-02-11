class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>graph(n);
        for(vector<int>u : redEdges)
            graph[u[0]].push_back({u[1],0});
        
        for(vector<int>u : blueEdges)
            graph[u[0]].push_back({u[1],1});
        
        vector<int>res(n,-1);
        vector<vector<int>>vis(n,vector<int>(2));
        queue<vector<int>>q;
        q.push({0,0,-1});
        res[0] = 0;
        vis[0][1] = 1;
        vis[0][0] = 1;
        while(!q.empty())
        {
            auto cur = q.front();
            q.pop();
            for(auto child : graph[cur[0]])
            {
                
                if (child.second != cur[2] && !vis[child.first][child.second])
                {
                    q.push({child.first,cur[1]+1,child.second});
                    vis[child.first][child.second] = true;
                    if (res[child.first] == -1)
                        res[child.first] = cur[1] + 1;
                }
            }
        }
        return res;
    }
};
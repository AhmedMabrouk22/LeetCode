class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        map<int,vector<int>>graph;
        for(int i = 0 ; i < routes.size(); ++i)
        {
            for(auto node : routes[i])
                graph[node].push_back(i);
        }
        
        int cnt = 1;
        
        queue<int>q;
        map<int,bool>vis;
        for(auto i : graph[source])
        {
            q.push(i);
            vis[i] = true;
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            
            for(int i = 0; i < sz; ++i)
            {
                int cur = q.front();
                q.pop();
                for(auto child: routes[cur])
                {
                    if (child == target) return cnt;
                    for(auto i : graph[child])
                    {
                        if (!vis[i])
                        {
                            vis[i] = true;
                            q.push(i);
                        }
                    }
                }
            }
            ++cnt;
        }
        
        return -1;
    }
};
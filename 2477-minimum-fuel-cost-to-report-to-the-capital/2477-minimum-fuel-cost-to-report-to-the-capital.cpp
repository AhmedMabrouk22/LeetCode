class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n = roads.size();
        vector<vector<int>>graph(n+1);
        vector<int>deg(n+1);
        for(vector<int> v : roads)
        {
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
            ++deg[v[0]];
            ++deg[v[1]];
        }
        
        queue<int>q;
        for(int i = 1;i<=n;++i)
        {
            if (deg[i] == 1)
                q.push(i);
        }
        
        long long res = 0;
        vector<int>len(n+1,1);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            res += ceil((double)len[cur]/seats);
            
            for(auto child : graph[cur])
            {
                --deg[child];
                len[child] += len[cur];
                if (deg[child] == 1 && child != 0)
                    q.push (child);
            }
        }
        
        return res;
    }
};
class DSU
{
public:
    unordered_map<int,int>parent;
    unordered_map<int,int>rank;
    int count;
    DSU(vector<vector<int>>& stones)
    {
       for(auto stone : stones)
       {
           int row = -(stone[0] + 1);
           int col = stone[1] + 1;
           parent[row] = row;
           parent[col] = col;
       }
       count = parent.size();
    }
    
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void union_sets(int x, int y)
    {
        int a = find(x);
        int b = find(y);
        if (a != b)
        {
            --count;
            if(rank[b] > rank[a])
                swap(a,b);
            parent[b]= a;
            if(rank[a] == rank[b])
                ++rank[a];
        }
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu(stones);
        for(auto stone : stones)
        {
           int row = -(stone[0] + 1);
           int col = stone[1] + 1;
           dsu.union_sets(row,col);
        }
        return stones.size() - dsu.count;
    }
};
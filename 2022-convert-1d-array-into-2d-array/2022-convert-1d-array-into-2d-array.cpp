class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>res;
        if (m*n != original.size()) return res;
        res = vector<vector<int>>(m,vector<int>(n));
        int idx = 0;
        for(int i = 0 ; i < m; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
                res[i][j] = original[idx++];
        }
        
        return res;
    }
};
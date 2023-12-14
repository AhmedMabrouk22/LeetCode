class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        map<int,int>row1,col1,row0,col0;
        for(int i = 0 ; i < grid.size(); ++i) {
            for(int j = 0 ; j < grid[0].size(); ++j) {
                row1[i] += grid[i][j] == 1;
                col1[j] += grid[i][j] == 1;
                row0[i] += grid[i][j] != 1;
                col0[j] += grid[i][j] != 1;
            }
        }

        vector<vector<int>>diff;
        for(int i = 0 ; i <grid.size() ; ++i) {
            vector<int>v(grid[0].size());
            for(int j = 0 ; j < grid[0].size(); ++j) {
                v[j] = row1[i] + col1[j] - row0[i] - col0[j]; 
            }
            diff.push_back(v);
        }
        return diff;
    }
};
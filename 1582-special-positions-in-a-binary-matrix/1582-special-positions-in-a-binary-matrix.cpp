class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int,int>row,col;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                row[i] += mat[i][j] == 1;
                col[j] += mat[i][j] == 1;
            }
        }
        
        int cnt = 0;
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < m ; ++j) {
                if (mat[i][j] && row[i] == 1 && col[j] == 1) ++cnt;
            }
        }
        
        return cnt;
        
    }
};
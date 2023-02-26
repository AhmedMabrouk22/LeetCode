class Solution {
public:
    int memo[505][505];
    int n,m;
    string str1,str2;
    int solve(int i,int j)
    {
        if (i == n || j == m)
            return (n-i) + (m-j);
        if (memo[i][j] != -1)
            return memo[i][j];
        
        if (str1[i] == str2[j])
            return memo[i][j] = solve(i+1,j+1);
        
        return memo[i][j] = 1 + min({
            solve(i,j+1),
            solve(i+1,j),
            solve(i+1,j+1)
        });
        
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        str1 = word1;
        str2 = word2;
        memset(memo,-1,sizeof(memo));
        return solve(0,0);
    }
};
class Solution {
public:
    
    int memo[1005][1005];
    string str1,str2;
    int LCS(int i, int j)
    {
        if(i == str1.size() || j == str2.size())
            return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        if(str1[i] == str2[j])
            return memo[i][j] =  1 + LCS(i+1, j+1);

        int choice1 = LCS(i+1, j);
        int choice2 = LCS(i, j+1);

        
        return memo[i][j] = max(choice1, choice2);
    }

    
    int longestCommonSubsequence(string text1, string text2) {
        str1 = text1;
        str2 = text2;
        memset(memo,-1,sizeof(memo));
        return LCS(0,0);
    }
};
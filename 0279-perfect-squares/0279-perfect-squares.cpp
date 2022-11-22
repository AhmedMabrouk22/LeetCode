class Solution {
public:
    int solve(int i,vector<int>&memo){
        if(i==0) return 0;
        if(memo[i]!=-1) return memo[i];
        int minCnt=INT_MAX;
        for(int num=1;num<=sqrt(i);++num){
            int curCnt=1+solve(i-(num*num),memo);
            minCnt=min(curCnt,minCnt);
        }
        return memo[i]=minCnt;
    }
    
    int numSquares(int n) {
        vector<int>memo(n+1,-1);
        return solve(n,memo);
    }
};
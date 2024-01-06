class Solution {
public:

    int solve(int i, vector<vector<int>>&job, vector<int>&startTime, int n,vector<int>&memo){
        if(i>=n)return 0;
        if(memo[i]!=-1)return memo[i];
        
        int idx = lower_bound(startTime.begin(),startTime.end(),job[i][1])-startTime.begin();
        int ch1 = job[i][2] + solve(idx,job,startTime,n,memo);
        int ch2 = solve(i+1,job,startTime,n,memo);
        return memo[i] = max(ch1,ch2);

    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>>job;
        vector<int>memo(n,-1);
        for(int i =0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(job.begin(),job.end());
        sort(startTime.begin(),startTime.end());
        return solve(0,job,startTime,n,memo);
        }
};
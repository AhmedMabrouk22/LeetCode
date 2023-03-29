class Solution {
public:
    int solve(vector<int>& satisfaction, vector<vector<int>>& memo, int i, int t) {
        if (i == satisfaction.size()) {
            return 0;
        }
        
        if (memo[i][t] != -1) {
            return memo[i][t];
        }
        
        return memo[i][t] = max(satisfaction[i] * t + solve(satisfaction, memo, i + 1, t + 1), 
                                       solve(satisfaction, memo, i + 1, t));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> memo(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        
        return solve(satisfaction, memo, 0, 1);
    }
};
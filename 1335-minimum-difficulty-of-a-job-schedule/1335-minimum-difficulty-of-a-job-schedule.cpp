class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        return minDifficultyVersion(jobDifficulty, d);
    }

    int minDifficultyVersion(const vector<int>& jobDifficulty, int d) {
        const int n = static_cast<int>(jobDifficulty.size());

        if (n < d) {
            return -1;
        } else if (n == d) {
            int totalDifficulty = 0;
            for (int difficulty : jobDifficulty)
                totalDifficulty += difficulty;
            return totalDifficulty;
        }

        vector<int> dp(n);
        dp[0] = jobDifficulty[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(jobDifficulty[i], dp[i - 1]);
        }

        vector<int> dpPrev(n);

        for (int i = 1; i < d; ++i) {
            dp.swap(dpPrev);
            for (int j = i; j < n; ++j) {
                int lastDayDifficulty = jobDifficulty[j];
                int tmpMin = lastDayDifficulty + dpPrev[j - 1];

                for (int t = j - 1; i - 1 < t; --t) {
                    lastDayDifficulty = max(lastDayDifficulty, jobDifficulty[t]);
                    tmpMin = min(tmpMin, lastDayDifficulty + dpPrev[t - 1]);
                }

                dp[j] = tmpMin;
            }
        }

        return dp.back();
    }
};

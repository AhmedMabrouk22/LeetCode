class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>s1,s2;
        vector<long long>l(n),r(n,n);
        int MOD = 1e9 + 7;
        for(int i = 0 ; i < n ; ++i)
        {
            while (!s1.empty() && arr[s1.top()] > arr[i]) s1.pop();
            l[i] = s1.empty() ? i+1 : i - s1.top();
            s1.push(i);
        }

        for(int i = n - 1 ; i >= 0 ; --i)
        {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) s2.pop();
            r[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; ++i) 
            res = ((res % MOD) + ((arr[i] * l[i] * r[i]) % MOD)) % MOD;

        return res;

    }
};
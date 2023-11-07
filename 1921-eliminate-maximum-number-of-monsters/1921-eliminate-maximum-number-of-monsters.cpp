class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<double>v;
        for(int i = 0 ; i < dist.size() ; ++i)
            v.push_back((double)dist[i]/speed[i]);
        sort(v.begin(),v.end());
        int res= 0;
        for(int i = 0 ; i < v.size() ; ++i)
        {
            if (v[i] <= i)
                return i;
        }
        return v.size();
    }
};
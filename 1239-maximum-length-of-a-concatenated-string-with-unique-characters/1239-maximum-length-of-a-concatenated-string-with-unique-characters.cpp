class Solution {
public:
    
    int res = 0;
    void solve(int i, string s,vector<string>& arr)
    {
        if (!isValid(s)) return;
        
        if (i >= arr.size())
        {
            res = max(res,(int)s.size());
            return;
        }
        
        solve(i+1,s,arr);
        solve(i+1, s + arr[i], arr);
    }
    
    bool isValid(string s){

        set<char> st;
        
        for(auto x : s){
            st.insert(x);
        }

        if(s.size() == st.size()){
            return true;
        }
        
        return false;
    }
    
    int maxLength(vector<string>& arr) {
        solve(0,"",arr);
        return res;
    }
};
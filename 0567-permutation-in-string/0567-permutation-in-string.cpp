class Solution {
public:
    map<char,int>mp1,mp2;
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size())
            return false;
        
        for(auto i : s1)
            ++mp1[i];
        
        for(int i = 0 ; i < s1.size(); ++i)
            ++mp2[s2[i]];
        if (valid())
            return true;
        
        int r = s1.size();
        for(int i = 0 ; i < s2.size() && r < s2.size() ; ++i)
        {
            ++mp2[s2[r]];
            --mp2[s2[i]];
            if (valid())
                return true;
            ++r;
        }
        return false;
    }
    
    bool valid()
    {
        for(char i ='a' ; i <= 'z' ; ++i)
        {
            if (mp1[i] != mp2[i])
                return false;
        }
        return true;
            
    }
};
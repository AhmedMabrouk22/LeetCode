class Solution {
public:
    int appendCharacters(string s, string t) {
        int p1 = 0 , p2 = 0;
        int s1 = s.size(), s2 = t.size();
        
        while(p1 < s1 && p2 < s2)
        {
            if (s[p1] == t[p2]) 
                ++p2;
            ++p1;
        }
        
        return s2 - p2;
    }
};
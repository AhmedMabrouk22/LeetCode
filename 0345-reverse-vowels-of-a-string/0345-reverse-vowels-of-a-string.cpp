class Solution {
public:
    
     bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u'
            || c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    }
    
    
    string reverseVowels(string s) {
        int l = 0 , r = s.size()-1;
        while(l < r)
        {
            if (!isVowel(s[l]))
                ++l;
            if (!isVowel(s[r]))
                --r;
            
            if (isVowel(s[l]) && isVowel(s[r]))
                swap(s[l++],s[r--]);
                
        }
        return s;
    }
};
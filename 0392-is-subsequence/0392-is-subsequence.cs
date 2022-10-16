public class Solution {
    public bool IsSubsequence(string s, string t) {
      int p = 0;
        
            if (s.Length == 0)
                return true;
        
            if (s.Length > t.Length)
                return false;
            for(int i = 0 ; i < t.Length;++i)
            {
                if (p < s.Length && s[p] == t[i])
                    ++p;
            }
            if (p == s.Length)
                return true;
            else
                return false;  
    }
}
public class Solution {
    public bool IsIsomorphic(string s, string t) {
        var str1 = new Dictionary<char, char>();
        var str2 = new Dictionary<char, char>();
        for(int i = 0 ; i < s.Length;++i)
        {
            var a = s[i];
            var b = t[i];

            if (str1.ContainsKey(a) && str1[a] != b)
                return false;

            if (str2.ContainsKey(b) && str2[b] != a)
                return false;

            str1[a] = b;
            str2[b] = a;


        }
        return true;
    }
}
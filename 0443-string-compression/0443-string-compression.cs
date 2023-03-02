public class Solution {
    public int Compress(char[] chars)
    {
        int p1 = 0, p2 = 1;
        int res = 0,i = 0;

        while(p1< chars.Length)
        {
            int cnt = 0;
            while (p2 < chars.Length && chars[p1] == chars[p2])
                ++p2;

            cnt = p2 - p1;
            chars[i++] = chars[p1];
            if (cnt > 1)
            {    
                
                string num = cnt.ToString();
                foreach (var x in num)
                    chars[i++] = x;
                res += num.Length;
                
            }
            res += 1;
            p1 = p2++;
        }
        return Math.Max(res, 1);
    }
}
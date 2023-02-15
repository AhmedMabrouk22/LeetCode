public class Solution {
    public IList<int> AddToArrayForm(int[] num, int k) {
        var res = new List<int>();
        int id = num.Length - 1;
        while(k > 0)
        {
            if (id >= 0)
                k += num[id--];
            res.Add(k % 10);
            k /= 10;
        }
        
        while(id >= 0)
            res.Add(num[id--]);
        res.Reverse();
        return res;
    }
}
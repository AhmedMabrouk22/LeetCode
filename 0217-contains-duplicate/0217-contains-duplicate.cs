public class Solution {
    public bool ContainsDuplicate(int[] nums)
    {
        Dictionary<int,int> mp = new Dictionary<int, int>();
        foreach(var i in nums)
        {
            if (mp.ContainsKey(i))
                return true;
            mp.Add(i, 1);
        }
        return false;
    }
}
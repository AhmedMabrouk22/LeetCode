public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; ++i)
            map[nums[i]] = i;
        
        for(int i = 0 ; i < nums.Length;++i)
        {
            int x = target - nums[i];
            if (map.ContainsKey(x) && i != map[x])
                return new int[] {i,map[x]};    
        }
        
        return new int[] {0,0};
    }
}
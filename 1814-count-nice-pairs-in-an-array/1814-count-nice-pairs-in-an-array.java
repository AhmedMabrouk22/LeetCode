import java.util.HashMap;

class Solution {
    int rev(int n) {
        int res = 0;
        while (n > 0) {
            res *= 10;
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    public int countNicePairs(int[] nums) {
        HashMap<Integer,Integer> map = new HashMap();
        for(int i : nums) {
            int x = i - rev(i);
            map.put(x,1 + map.getOrDefault(x,0));
        }
        int res = 0 , mod = (int)1e9 + 7;
        for(int i : nums) {
            int x = i - rev(i);
            if (map.containsKey(x)) {
                int cnt = map.get(x) - 1;
                res = ((res % mod) + (cnt % mod)) % mod;
                map.put(x,cnt);
            }
        }
        return res;
    }
}
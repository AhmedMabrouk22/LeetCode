class Solution {
    public int maxOperations(int[] nums, int k) {
        int cnt= 0;
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i : nums) {
            int t = k - i;
            if (mp.containsKey(t)) {
                ++cnt;
                if (mp.get(t) == 1) mp.remove(t);
                else mp.put(t,mp.get(t) - 1);
            }
            else {
                mp.put(i, mp.getOrDefault(i,0) + 1);
            }
        }
        return cnt;
    }
}
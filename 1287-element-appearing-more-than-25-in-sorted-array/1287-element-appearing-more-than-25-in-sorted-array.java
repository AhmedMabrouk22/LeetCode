class Solution {
    public int findSpecialInteger(int[] arr) {
        double x = Math.ceil(arr.length * 0.25);
        Map<Integer,Integer> mp = new HashMap();
        int res = 0;
        for (int i : arr) {
            mp.put(i,mp.getOrDefault(i,0)+1);
            if (mp.get(i) >= (int)x) {
                res = i;
            }
        }
        return res;
    }
}
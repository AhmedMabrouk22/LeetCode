class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> res = new ArrayList();
        int mx = 0;
        for(int i = 0 ; i < candies.length ; ++i)
            mx = Math.max(mx, candies[i]);
        for(int i = 0 ; i < candies.length; ++i)
            res.add(candies[i] + extraCandies >= mx);
        return res;
    }
}
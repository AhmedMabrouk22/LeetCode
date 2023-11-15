public class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int mx = 1;
        int n = arr.length;
        if (arr[0] != 1) arr[0] = 1;
        for(int i = 1 ; i < n ; ++i) {
            if (Math.abs(arr[i] - arr[i-1]) > 1) arr[i] = arr[i-1] + 1;
            mx = Math.max(arr[i],mx);
        }
        return mx;
    }
}

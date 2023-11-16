public class Solution {
    int n;
    String[] arr;
    String res ;
    void solve(String str, int i) {
        if (i == n) {
            for(int x = 0 ; x < n ;++x) {
                if (str.equals(arr[x])) {
                    return;
                }
            }
            res = str;
            return;
        }

        solve(str + '1',i + 1);
        solve(str + '0',i + 1);
    }
    public String findDifferentBinaryString(String[] nums) {
        n = nums.length;
        arr = nums;
        solve("",0);
        return res;
    }
}

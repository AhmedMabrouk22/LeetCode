public class Solution {
    public int FindKthPositive(int[] arr, int k) {
        int n = arr.Length;
        bool[] frq = new bool[3005];
        var list = new List<int>();
        for (int i = 0; i < n; ++i)
            frq[arr[i]] = true;
        for(int i = 1; i<=3000;++i)
        {
            if (!frq[i])
                list.Add(i);
        }
        return list[k-1];
    }
}
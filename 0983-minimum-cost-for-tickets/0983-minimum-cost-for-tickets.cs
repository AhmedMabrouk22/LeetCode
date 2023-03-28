public class Solution
{
    private int[] memo = new int[370];
    int[] d = new[] { 1, 7, 30 };
    int Solve(int i,int[] days, int[] costs)
    {
        if (i == days.Length)
            return 0;
        if (memo[i] != -1)
            return memo[i];

        memo[i] = (int)1e6;
        int j = i;
        for (int x = 0; x < 3; ++x)
        {
            while (j < days.Length && days[j] < days[i] + d[x])
                ++j;
            memo[i] = Math.Min(memo[i], Solve(j, days, costs) + costs[x]);
        }

        return memo[i];
    }

    public int MincostTickets(int[] days, int[] costs)
    {
        for (int i = 0; i < 370; ++i) memo[i] = -1;
        return Solve(0,days,costs);
    }
}
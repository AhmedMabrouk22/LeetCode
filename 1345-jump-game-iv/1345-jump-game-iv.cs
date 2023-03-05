public class Solution {
    public int MinJumps(int[] arr)
    {
        int n = arr.Length;
        var q = new Queue<int>();
        bool[] vis = new bool[n + 1];
        var mp = new Dictionary<int, List<int>>();

        for (int i = 0; i < n; ++i)
        {
            if (mp.ContainsKey(arr[i]))
                mp[arr[i]].Add(i);
            else
                mp.Add(arr[i],new List<int>{i});
        }

        q.Enqueue(0);
        vis[0] = true;
        int steps = 0;
        while(q.Count != 0)
        {

            int sz = q.Count;
            while(sz-- > 0)
            {
                int cur = q.Dequeue();
                if (cur == n - 1)
                    return steps;

                if (cur -1 >= 0 && !vis[cur-1])
                {
                    q.Enqueue(cur -1);
                    vis[cur - 1] = true;
                }

                if (cur + 1 < n && !vis[cur + 1])
                {
                    q.Enqueue(cur + 1);
                    vis[cur + 1] = true;
                }

                if (mp.ContainsKey(arr[cur]))
                {
                    foreach (var x in mp[arr[cur]])
                    {
                        if (!vis[x])
                        {
                            q.Enqueue(x);
                            vis[x] = true;
                        }
                    }
                    mp[arr[cur]].Clear();
                }
            }
            ++steps;
        }

        return steps;
    }
}
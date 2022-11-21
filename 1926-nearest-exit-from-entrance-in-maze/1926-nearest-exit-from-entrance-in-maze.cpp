class Solution {
public:

	bool valid(int r, int c, int m, int n)
	{
		return r >= 0 && r < m && c >= 0 && c < n;
	}
	int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
		int m = maze.size();
		int n = maze[0].size();
		int dy[] { 0, 0, 1, -1};
		int dx[] { 1, -1, 0, 0 };
		map<pair<int, int>, int>len;
		queue<pair<int, int>>q;
		q.push({ entrance[0], entrance[1] });
		len[{ entrance[0], entrance[1] }] = 0;
		while (!q.empty())
		{
			pair<int, int>cur = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i)
			{
				int x = cur.first + dx[i];
				int y = cur.second + dy[i];
				if (valid(x, y,m,n) && maze[x][y] == '.' &&!len.count({ x, y }))
				{
					q.push({ x, y });
					len[{x, y}] = len[{cur.first, cur.second}] + 1;
				}
			}
            
            if (cur.first == entrance[0] && cur.second == entrance[1])
                continue;
            
            if (cur.first == m - 1 || cur.first == 0 || cur.second == n - 1 || cur.second == 0)
				return len[{cur.first, cur.second}];
		}
        return -1;
	}
};
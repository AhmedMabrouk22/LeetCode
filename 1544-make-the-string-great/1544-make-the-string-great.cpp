class Solution {
public:
	string makeGood(string s) {
		stack<char>st;
		for (auto i : s)
		{
			if (st.empty())
				st.push(i);
			else
			{
				if (st.top() != i && (st.top() == tolower(i) || tolower(st.top()) == i))
					st.pop();
				else
					st.push(i);
			}
		}
		string res;
		while (!st.empty())
		{
			res.push_back(st.top());
			st.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

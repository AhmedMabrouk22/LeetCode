class Solution {
public:
	int romanToInt(string s) {
		string ch = "IVXLCDM";
		int arr[7] = { 1, 5, 10, 50, 100, 500, 1000 };
		map<char, pair<int,int>>mp;
		for (int i = 0; i < 7; ++i)
			mp[ch[i]] = { arr[i], i };

		int res = 0;
		s += '!';
		for (int i = 0; i < s.size(); ++i)
		{
			if (mp[s[i]].second >= mp[s[i + 1]].second)
				res += mp[s[i]].first;
			else
			{
				res += mp[s[i + 1]].first - mp[s[i]].first;
				i += 1;
			}
		}
		return res;
	}
};

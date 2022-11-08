class Solution {
public:
	int romanToInt(string s) {
		string ch = "IVXLCDM";
		int arr[7] = { 1, 5, 10, 50, 100, 500, 1000 };
		unordered_map<char,int>mp;
		for (int i = 0; i < 7; ++i)
			mp[ch[i]] = arr[i];

		int res = 0;
		s += '!';
		for (int i = 0; i < s.size(); ++i)
		{
			if (mp[s[i]] >= mp[s[i + 1]])
				res += mp[s[i]];
			else
			{
				res += mp[s[i + 1]] - mp[s[i]];
				i += 1;
			}
		}
		return res;
	}
};

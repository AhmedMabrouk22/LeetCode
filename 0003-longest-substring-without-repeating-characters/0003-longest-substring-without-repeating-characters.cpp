class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0, cnt = 0;
		int en = 0;
		unordered_map<char, int>mp;
		for (int st = 0; st < s.size()  && en < s.size(); ++st)
		{
			while (!mp[s[en]] && en < s.size())
			{
				++cnt;
				++mp[s[en]];
				++en;
			}
			res = max(res, cnt);
			--mp[s[st]];
			--cnt;
		}
		return res;
	}
};
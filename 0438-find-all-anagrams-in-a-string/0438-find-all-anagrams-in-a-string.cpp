class Solution {
public:
	map<char, int>mp1, mp2;
	vector<int> findAnagrams(string s, string p) {
		vector<int>res;
		for (auto i : p)
			++mp1[i];

		for (int i = 0; i < p.size(); ++i)
			++mp2[s[i]];
		
		if (valid())
			res.push_back(0);

		int r = p.size();
		int l = 0;
		while (r < s.size())
		{
			++mp2[s[r]];
			--mp2[s[l]];
			++r;
			++l;
			if (valid())
				res.push_back(l);
		}
		return res;
	}

	bool valid()
	{
		for (char i = 'a'; i <= 'z'; ++i)
		{
			if (mp1[i] != mp2[i])
				return false;
		}
		return true;
	}

};
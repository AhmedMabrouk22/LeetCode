class Solution {
public:
	
	string mp[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> res;

	void solve(int idx, string digits, string str)
	{
		if (idx == digits.size())
		{
			res.push_back(str);
			return;
		}

		string val = mp[digits[idx] - '0'];
		for (int i = 0; i < val.size(); ++i)
		{
			str += val[i];
			solve(idx + 1, digits, str);
			str.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
        if (digits == "")
            return res;
        
		solve(0, digits, "");
		return res;
	}
};
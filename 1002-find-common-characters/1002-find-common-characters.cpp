class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>common(26),cur;
        for(auto i : words[0])
            ++common[i - 'a'];
        
        for(int i = 1 ; i < words.size(); ++i)
        {
            cur = vector<int>(26,0);
            
            for(auto x : words[i])
                ++cur[x - 'a'];
            
            for(int j = 0 ; j < 26 ; ++j)
                common[j] = min(common[j],cur[j]);
        }
        
        vector<string>res;
        
        for(int i = 0 ; i < 26; ++i)
        {
            while(common[i])
            {
                res.push_back(string(1,i + 'a'));
                --common[i];
            }
        }
        
        return res;
    }
};
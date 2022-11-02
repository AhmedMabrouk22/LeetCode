class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,int>valid;
        queue<string>q;
        q.push(start);
        valid[start] = 0;
        string str = "ACGT";
        while(!q.empty())
        {
            string cur = q.front();
            q.pop();
            
            if (cur == end)
                return valid[cur];
            
            for(int i = 0 ; i < start.size();++i)
            {
                string temp = cur;
                for(int j = 0 ; j < 4;++j)
                {
                    cur[i] = str[j];
                    if (find(bank.begin(),bank.end(),cur) != bank.end() && !valid.count(cur))
                    {
                        valid[cur] = valid[temp]+1;
                        q.push(cur);
                    }
                }
                cur = temp;
            }
        }
        return -1;
    }
};
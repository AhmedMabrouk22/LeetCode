class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        
        map<int,int>mp;
        for(auto i : hand) ++mp[i];
        
        while(!mp.empty()) {
            int cur = mp.begin()->first;
            
            for(int i = 0 ; i < groupSize; ++i)
            {
                if (!mp[cur + i]) return false;
                
                --mp[cur + i];
                if(!mp[cur + i]) 
                    mp.erase(cur + i);
            }
        }
        
        return true;
    }
};
class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool find(int val) 
    {
        if (mp.find(val) != mp.end())
            return true;
        return false;
    }
    
    bool insert(int val) {
        if (find(val)) return false;
        
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (!find(val)) return false;
        auto idx = mp.find(val);
        v[idx->second] = v.back();
        v.pop_back();
        mp[v[idx->second]] = idx -> second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
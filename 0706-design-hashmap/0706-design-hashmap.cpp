class MyHashMap {
public:
    vector<int>frq;
    MyHashMap() {
        frq = vector<int>((int)1e6+5,-1);
    }
    
    void put(int key, int value) {
        frq[key] = value;
    }
    
    int get(int key) {
        return frq[key];
    }
    
    void remove(int key) {
        frq[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
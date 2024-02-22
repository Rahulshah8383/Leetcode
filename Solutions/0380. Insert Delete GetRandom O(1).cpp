class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> Mymap;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(Mymap.find(val) != Mymap.end())
            return false;

        v.push_back(val);
        Mymap[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(Mymap.find(val) == Mymap.end())
            return false;

        auto it = Mymap.find(val);
        v[it->second] = v.back();
        v.pop_back();
        Mymap[v[it->second]] = it->second;
        Mymap.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

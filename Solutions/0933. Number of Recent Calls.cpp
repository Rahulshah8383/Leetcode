class RecentCounter {
public:
    vector<int> l;
    
    RecentCounter() {
    }
    
    int ping(int t) {
        l.push_back(t);

        int low = t-3000;
        int temp = 0;
        for(int i=0;i<l.size();i++){
            if(l[i] < low){
                temp++;
            }
        }
        
        return l.size() - temp;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

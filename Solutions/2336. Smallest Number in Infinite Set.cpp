class SmallestInfiniteSet {
public:
    priority_queue<int , vector<int> , greater<int>>pq;
    SmallestInfiniteSet() {
        for(int i=1001;i>0;i--)pq.push(i);
    }
    int popSmallest() {
        int x = pq.top();
        while(pq.top()==x)
        pq.pop();
        return x;
    }
    void addBack(int num) {
        pq.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

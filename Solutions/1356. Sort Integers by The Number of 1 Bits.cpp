class Solution {
public:
    static bool cmp(int a, int b){
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);

        // cout<<a<<" : "<<x<<" "<<b<<": "<<y<<endl;
        return (countA == countB)?a<b:countA < countB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

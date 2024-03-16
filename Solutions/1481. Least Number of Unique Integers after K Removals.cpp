class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }

        // base case
        if(arr.size() == k){ return 0; }
        
        if(k == 0){ return m.size(); }


        vector<int> v;
        for(auto x : m){
            v.push_back(x.second);
        }

        sort(v.begin(), v.end());

        int i=0;
        while(k){
            if(v[i] > k){
                k = 0;
            }
            else{
                k -= v[i];
                i++;
            }
        }
        // cout<<v.size()<<" "<<i;

        return v.size() - i;

    }
};

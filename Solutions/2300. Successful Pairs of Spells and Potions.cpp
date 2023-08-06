class Solution {
    private:
    int64_t ceil_divide(int64_t a, int64_t b) {
        return (a + b - 1) / b;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //     // vector<int> ans;
    //     // sort(potions.begin(), potions.end());

    //     // int n = spells.size();
    //     // int m = potions.size();

    //     // for(int i=0;i<n;i++){
    //     //     int cnt = 0;
    //     //     for(int j=0;j<m;j++){
    //     //         long long pro = (long long)spells[i]*(long long)potions[j];

    //     //         if(pro >= success)
    //     //         cnt++;
    //     //     }
    //     //     ans.push_back(cnt);
    //     // }

    //     vector<int> ans;
    // int n = spells.size();
    // int m = potions.size();
    // const long long MOD = 1000000007;
    // sort(potions.begin(), potions.end());

    // for(int i=0; i<n; i++){
    //     int l = 0, r = m-1, last = -1;
    //     while(l <= r){
    //         int mid = l + (r-l)/2;
    //         if((long long)spells[i]*potions[mid] <= success){
    //             last = mid;
    //             l = mid+1;
    //         }
    //         else{
    //             r = mid-1;
    //         }
    //     }
    //     ans.push_back(last == -1 ? 0 : m-last);
    // }
    // return ans;  

        sort(begin(potions), end(potions));
            vector<int> result;
            for (const auto& s: spells) {
                result.emplace_back(size(potions) - distance(cbegin(potions), lower_bound(cbegin(potions), cend(potions), ceil_divide(success, s))));
            }
            return result;
    }
    
};

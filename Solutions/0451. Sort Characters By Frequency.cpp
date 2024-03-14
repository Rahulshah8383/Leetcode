class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> res(256, {0, ' '});
        for(int i=0;i<s.size();i++){
            res[s[i]].first++;
            res[s[i]].second=s[i];
        }

        sort(res.rbegin(), res.rend());

        string ans;
        for(auto x : res){
            if(x.first == 0){
                continue;
            }
            ans += string(x.first, x.second);
        }

        return ans;
    }
};

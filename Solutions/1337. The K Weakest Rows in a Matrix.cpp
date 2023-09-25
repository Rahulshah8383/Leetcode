class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // map<number of soldier, row>
        vector<pair<int, int>> v;
        vector<int> ans;

        for(int i=0;i<mat.size();i++){
            int soldier = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1)
                    soldier++;
            }

            pair<int, int> p = make_pair(soldier, i);
            v.push_back(p);
        }

        sort(v.begin(), v.end());

        // for(int i=0;i<v.size();i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }

        return ans;
    }
};

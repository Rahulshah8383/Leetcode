class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();

        unordered_map<int, vector<int>> ump;

        for(int i=0;i<n;i++){
            ump[groupSizes[i]].push_back(i);
        }

        for(auto x : ump){
            int gropuSize = x.first;
            vector<int> temp = x.second;

            int size = temp.size()/gropuSize;
            int l = 0;

            for(int i=0;i<size;i++){
                vector<int> group;
                for(int j=0;j<gropuSize;j++){
                    group.push_back(temp[l]);
                    l++;
                }
                ans.push_back(group);
            }
        }
        return ans;
    }
};

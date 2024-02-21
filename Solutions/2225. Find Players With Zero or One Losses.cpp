class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> first;
        unordered_map<int, int> second;

        for (int i = 0; i < matches.size(); i++) {
            int x = matches[i][0];
            int y = matches[i][1];

            first[x]++;
            second[y]++;
        }

        vector<int> winner;
        for (auto it : first) {
            if (second.find(it.first) == second.end()) {
                winner.push_back(it.first);
            }
        }
        sort(winner.begin(), winner.end());

        vector<int> loser;
        for (auto it : second) {
            if (it.second == 1) {
                loser.push_back(it.first);
            }
        }
        sort(loser.begin(), loser.end());

        vector<vector<int>> ans;
        ans.push_back(winner);
        ans.push_back(loser);        

        return ans;
    }
};

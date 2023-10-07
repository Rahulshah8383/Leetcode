class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        /*
        unordered_map<int, int> cnt;

        for(int i=0;i<edges.size();i++){
            int a = edges[i][0];
            int b = edges[i][1];
            cnt[a]++;
            cnt[b]++;
        }

        int ans = -1, maxi = 0;
        for(auto it : cnt){
            // cout<<it.first<<" "<<it.second<<endl;
            if(maxi < it.second){
                ans = it.first;
                maxi = it.second;
            }
        }

        return ans;
        */
        int n = edges.size();
        vector<int> adj[n+2];

        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        for(int i=1;i<=n+1;i++){
            if(adj[i].size() == n)
                return i;
        }

        return 0;
    }
};

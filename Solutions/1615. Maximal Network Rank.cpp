class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        /*
        vector<int>ad[n+1];
        for(auto x:roads){
            ad[x[0]].push_back(x[1]);
            ad[x[1]].push_back(x[0]);
        }
        for(auto &x:ad){
            sort(x.begin(),x.end());
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp_ans = ad[i].size() + ad[j].size();
                int index = lower_bound(ad[i].begin(),ad[i].end(),j)-ad[i].begin();
                if(index!=ad[i].size()){
                    if(ad[i][index]==j)temp_ans--;
                }
                ans = max(ans, temp_ans);
            }
        }
        return ans;
        */

        vector<vector<bool>> adj(n , vector<bool>(n,false));
        vector<int> indegree(n, 0);

        for(auto it : roads){
            int u = it[0], v = it[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            indegree[u]++;
            indegree[v]++;
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, indegree[i]+indegree[j] - adj[i][j]);
            }
        }

        return ans;
    }
};

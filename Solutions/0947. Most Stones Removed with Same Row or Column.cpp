class Solution {
public:
    void DFs(int node, vector<int> adj[], vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                DFs(it, adj, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]))
                    adj[i].push_back(j);
            }
        }

        vector<int> vis(n, 0);

        int ans = n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFs(i, adj, vis), ans--;
            }
        }
        return ans;
    }
};

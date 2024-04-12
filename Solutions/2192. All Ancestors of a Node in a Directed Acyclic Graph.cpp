class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        set<int> st[n];
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto it : adj[front]){
                st[it].insert(front);

                for(auto i : st[front]){
                    st[it].insert(i);
                }

                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        vector<vector<int>> ans(n);

        for(int i=0;i<n;i++){
            ans[i] = vector<int>(st[i].begin(), st[i].end());
        }

        return ans;
    }
};

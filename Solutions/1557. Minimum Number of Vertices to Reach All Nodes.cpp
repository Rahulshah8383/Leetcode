class Solution {
public:
    // n = 5
    // edges = [[0,1],[1,2],[3,2],[4,3],[4,2]]
    // Output : [0,3,4]
    // Expected : [0,4]
    /*
    void BFS(vector<int> adj[], vector<int> &vis, int node){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto it : adj[front]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> adj[n];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        // for(int i=0;i<n;i++){
        //     cout<<i<<" : ";
        //     for(auto i : adj[i]){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> vis(n, 0); 

        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);
                BFS(adj, vis, i);
            }
        }

        return ans;
    }
    */

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges){
        vector<int> ans;
        vector<int> adj[n];
        
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        // for(int i=0;i<n;i++){
        //     cout<<i<<" : ";
        //     for(auto i : adj[i]){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> indegree(n, 0);
		for (int i = 0; i < n; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

        for(int i=0;i<n;i++){
            // cout<<indegree[i]<<" ";
            if(indegree[i] == 0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};

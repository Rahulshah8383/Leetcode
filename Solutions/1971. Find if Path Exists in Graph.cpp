class Solution {
public:
    // bool DFS(vector<int> adj[], vector<int>& vis, int node, int destination){
    //     if(node == destination){
    //         return true;
    //     }
    //     vis[node] = 1;

    //     for (auto i : adj[node]){
    //         if (!vis[i]){
    //             if (DFS(adj, vis, i, destination)) {
    //                 return true;  // Return true if a path is found in the recursive call
    //             }
    //         }
    //     }

    //     return false;
    // }

    bool BFS(vector<int> adj[], vector<int>& vis, int node, int destination){
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            if(front == destination){
                return true;
            }

            for(auto it : adj[front]){
                if(!vis[it]){
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        // if(DFS(adj, vis, source, destination))
        if(BFS(adj, vis, source, destination))
        {
            return true;
        }

        return false;
    }
};

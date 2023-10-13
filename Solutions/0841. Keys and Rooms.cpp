class Solution {
public:
    int BFS(vector<int> adj[], vector<int> &vis, int node){
        queue<int> q;
        q.push(node);
        int count = 1;
        vis[node] = 1;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto it : adj[front]){
                if(!vis[it]){
                    count++;
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        return count;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> adj[n];        
        
        for(int i=0;i<n;i++){
            for(auto j : rooms[i]){
                adj[i].push_back(j);
            }
        }

        // for(int i=0;i<n;i++){
        //     cout<<i<<" : ";
        //     for(auto i : adj[i]){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> vis(n,0);
        int count = BFS(adj, vis, 0);

        return n==count;
    }
};

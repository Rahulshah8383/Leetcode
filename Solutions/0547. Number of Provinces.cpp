class Solution {
public:
    void BFS(int node, unordered_map<int, list<int>> &adjList, vector<int> &visited){
        visited[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int front = q.front(); q.pop();

            for(auto neighbour : adjList[front]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            } 
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        
        unordered_map<int, list<int>> adjList;
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }


        vector<int> visited(V, 0);
        int cnt = 0;

        for(int i=0;i<V;i++){
            if(!visited[i]){
                BFS(i, adjList, visited);
                cnt++;
            }
        }

        return cnt;
    }
};

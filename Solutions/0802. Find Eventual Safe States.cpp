class Solution {
public:
     bool dfs(vector<vector<int>>&AdjList, vector<bool>&visited, vector<bool> &dfsVisited, int node){
        visited[node] = true;
        dfsVisited[node] = true;

        for(auto neighbour : AdjList[node]){
            if(visited[neighbour] == false){
                bool cycleDetected = dfs(AdjList, visited, dfsVisited, neighbour);
                if(cycleDetected){
                    return true;
                }
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> AdjList(n);
       
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                AdjList[i].push_back(graph[i][j]);
            }
        }

        vector<bool> visited(n, false);
        vector<bool> dfsVisited(n, false);

        for(int i=0;i<n;i++){
            if(visited[i] == false){
                dfs(AdjList, visited, dfsVisited, i);
            }
        }

        vector<int>ans;
        for(int i=0;i<dfsVisited.size();i++){
          if(!dfsVisited[i])
          ans.push_back(i);
        }
        return ans;
    }
};

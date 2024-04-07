class Solution {
public:
    bool bfs(int start, vector<int> &color, vector<vector<int>>& graph){
        queue<int> q;
    
       q.push(start);
       color[start] = 0; // color first element with 0.

       while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto it : graph[front]){
            if(color[it] == -1){
                color[it] = !color[front];
                q.push(it);
            }
            else if(color[it] == color[front]){
                return false;
            }
        }
       }

        return true;
    }

    bool dfs(int start, int col, vector<int> &color, vector<vector<int>>& graph){    
       color[start] = col; // color first element with 0.

       for(auto it : graph[start]){
            if(color[it] == -1){
                if(dfs(it, !col, color, graph) == false){
                    return false;
                }
            }
            else if(color[it] == col){
                return false;
            }
       }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
       int V = graph.size();
        vector<int> color(V , -1);

        for(int i=0;i<V;i++){
            if(color[i] == -1){
                // if(!bfs(i, color, graph))
                if(!dfs(i, 0, color, graph))
                {
                    return false;
                }
            }
        }
       
       return true;
    }
};

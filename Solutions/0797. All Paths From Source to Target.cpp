class Solution {
public:
    void DFS(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> path, int node){
        path.push_back(node);

        if(node == graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto i : graph[node]){
                DFS(graph, ans, path, i);
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        DFS(graph, ans, path, 0);
        return ans;
    }
};

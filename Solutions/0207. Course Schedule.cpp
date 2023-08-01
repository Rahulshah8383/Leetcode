class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> AdjList[n];
        vector<int> indegree(n, 0);
        for(auto x : prerequisites){ 
            AdjList[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            ans.push_back(front);

            for(auto neighbour : AdjList[front]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return ans.size() == n;
    }
};

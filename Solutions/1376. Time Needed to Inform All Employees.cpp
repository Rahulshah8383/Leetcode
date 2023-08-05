class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<int> q;
        q.push(headID);

        int ans = informTime[headID];

        vector<vector<int>> graph(n);

        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1){
                graph[manager[i]].push_back(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int i=0;i<graph[front].size();i++){
                int next = graph[front][i];
                q.push(next);
                informTime[next] = informTime[next] + informTime[front];
                ans = max(ans, informTime[next]);
            }
        }

        return ans;
    }
};

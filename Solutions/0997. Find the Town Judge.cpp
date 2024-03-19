class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // unordered_map<int, list<int>> adjList;
        // for(int i=0;i<trust.size();i++){
        //     adjList[trust[i][0]].push_back(trust[i][1]);
        // }

        // int ans = -1;
        // for(auto  it : adjList){
        //     // cout<<it.first<<" : ";
        //     // for(auto i : it.second){
        //     //     cout<<i<<" ";
        //     // }
        //     // cout<<endl;

        //     if(it.second.size() == 0){
        //         ans = it.first;
        //     }
        // }

        vector<int> outdegree(n+1, 0);
        vector<int> indegre(n+1, 0);

        for(int i=0;i<trust.size();i++){
            int u = trust[i][0];
            int v = trust[i][1];

            outdegree[u]++;
            indegre[v]++;
        }
        
        int ans = -1;

        for(int i=1;i<=n;i++){
            // cout<<i<<" : "<<outdegree[i]<<" "<<indegre[i]<<endl;

            if(outdegree[i] == 0 && indegre[i] == n-1){
                ans =i;
            }
        }

        return ans;
    }
};

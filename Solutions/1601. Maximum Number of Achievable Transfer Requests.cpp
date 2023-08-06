class Solution {
public:
    int answer = 0;
    void Helper(vector<vector<int>>& requests, vector<int> &indegree, int n, int index, int count){
        if(index == requests.size()){
            // Check if all building have an in-degree of 0.
            for(int i=0;i<n;i++){
                if(indegree[i]){
                    return;
                }
            }

            answer = max(answer, count);
            return;
        }
        // Consider this request, increment and decrement for the builing involved
        indegree[requests[index][0]]--;
        indegree[requests[index][1]]++;

        // Move on to the next request and also increment the count of requests.
        Helper(requests, indegree, n, index+1, count+1);

        //Backtrack to the previousvalues to move back to the original state the second recusion
        indegree[requests[index][0]]++;
        indegree[requests[index][1]]--;

        // Ignore this request ns mocw on to the next request without incrementing the counter
        Helper(requests, indegree, n, index+1, count);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> indegree(n, 0);
        Helper(requests, indegree, n, 0, 0);

        return answer;
    }
};

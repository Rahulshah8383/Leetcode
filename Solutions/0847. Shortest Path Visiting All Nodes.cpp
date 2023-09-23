class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        // Adjacency list of graph
        vector<vector<int>> adjList(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adjList[i].push_back(graph[i][j]);
            }
        }

        vector<vector<int>> dist(1 << n, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            int lead = i;
            int mask = setBit(0, i);

            q.push({lead, mask});
            dist[mask][lead] = 0;
        }

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> path = q.front();
                q.pop();

                int lead = path.first;
                int mask = path.second;

                if (mask == (1 << n) - 1) { // All nodes visited
                    return dist[mask][lead];
                }

                // Iterate over neighbors of lead
                for (int child : adjList[lead]) {
                    int newLead = child;
                    int newMask = setBit(mask, newLead);

                    // Avoid cycle: Intelligent BFS: Check if this set is already visited
                    if (dist[newMask][newLead] != -1) {
                        continue;
                    }

                    dist[newMask][newLead] = dist[mask][lead] + 1;
                    q.push({newLead, newMask});
                }
            }
        }

        return 1221;
    }

private:
    int setBit(int mask, int i) {
        return mask | (1 << i);
    }
};

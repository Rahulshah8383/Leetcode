class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
    int ans = 0;

    vector<int> vis(n, 0);

    vector<int> minDist(n, INT_MAX); // Initialize minDist with infinity
    minDist[0] = 0; // Start with the first point

    for(int i = 0; i < n; i++) {
        int u = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        vis[u] = 1;
        ans += minDist[u];

        for(int v = 0; v < n; v++) {
            int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
            if(!vis[v] && dist < minDist[v]) {
                minDist[v] = dist;
            }
        }
    }

    return ans;
    }
};

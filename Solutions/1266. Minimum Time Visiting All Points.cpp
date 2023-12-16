class Solution {
public:
    int Helper(vector<int> p1, vector<int> p2){
        return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;

        for(int i=0;i<points.size()-1;i++){
            ans += Helper(points[i], points[i+1]);
        }

        return ans;
    }
};

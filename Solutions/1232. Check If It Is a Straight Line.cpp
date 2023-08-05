class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int size = coordinates.size();
        if(size < 2){
            return true;
        }
        
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        for(int i=2;i<size;i++){
            int x = coordinates[i][0], y = coordinates[i][1];
            
            if((y2-y1)*(x1-x) != (y1-y)*(x2-x1)){
                return false;
            }
        }

        return true;
    }
};

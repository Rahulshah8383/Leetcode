class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> brickUse;

        int i = 0;
        for(;i<heights.size()-1;i++){
            int jump = heights[i+1] - heights[i];

            if(jump <= 0){
                continue;
            }
            
            if(jump <= bricks){
                bricks -= jump;
                brickUse.push(jump);
            }

            else if(ladders > 0){
                if(brickUse.size() && brickUse.top() > jump){
                    int max = brickUse.top(); 
                    brickUse.pop();
                    bricks += max;
                    bricks -= jump;
                    brickUse.push(jump);
                }
                ladders--;
            }

            else
                break;
        }

        return i;
    }
};

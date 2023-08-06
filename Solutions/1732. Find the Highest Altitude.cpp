class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int temp = 0;
        for(int i=0;i<gain.size();i++){
            temp = temp + gain[i];
            if(temp > highest){
                highest = temp;
            }
        }
        return highest;
    }
};

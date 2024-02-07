class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        flowerbed.emplace(flowerbed.begin(), 0);
        flowerbed.emplace_back(0);

        for(int i=1;i<flowerbed.size()-1;i++){
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                flowerbed[i] = 1;
                cnt++;
            }
        }

        return cnt >= n? true : false;
    }
};

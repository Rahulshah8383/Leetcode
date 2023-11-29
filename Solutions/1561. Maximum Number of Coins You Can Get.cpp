class Solution {
public:
    int maxCoins(vector<int>& piles) {
       int size = piles.size();
       int i=0, j = size-1;
       int n = size/3; 
       sort(piles.begin(), piles.end());

       int sum = 0;
       for(int i=0;i<n;i++){
            j--;
            sum += piles[j];
            j--;
       }

       return sum;
    }
};

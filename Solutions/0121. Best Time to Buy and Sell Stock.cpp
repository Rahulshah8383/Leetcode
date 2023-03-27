class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int Buy = prices[0], max_profit = 0; 

       for(int i=0;i<prices.size();i++){
           if(Buy > prices[i]){
               Buy = prices[i];
           }

           else if(prices[i]-Buy > max_profit){
               max_profit = prices[i]-Buy;
           }
       }
       return max_profit;
    }
};

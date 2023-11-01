class Solution {
public:
    int maxProfit(vector<int>& prices) {
       // int Buy = prices[0], max_profit = 0; 

       // for(int i=0;i<prices.size();i++){
       //     if(Buy > prices[i]){
       //         Buy = prices[i];
       //     }

       //     else if(prices[i]-Buy > max_profit){
       //         max_profit = prices[i]-Buy;
       //     }
       // }
       // return max_profit;

        int mini = prices[0], max_profit = 0; 

       for(int i=0;i<prices.size();i++){
           int cost = prices[i] - mini;
           max_profit = max(max_profit, cost);
           mini = min(mini, prices[i]);
       }
       return max_profit;
    }
};

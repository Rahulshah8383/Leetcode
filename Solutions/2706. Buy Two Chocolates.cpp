class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());

        int a = prices[0];
        int b = prices[1];

        if(money >= (a+b)){
            return money - (a+b);
        }

        return money;
    }
};

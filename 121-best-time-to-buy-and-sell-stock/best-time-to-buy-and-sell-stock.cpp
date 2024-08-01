class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int cheapest = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < cheapest) {
                cheapest = prices[i];
            }
            else {
                if (prices[i] - cheapest > maxProfit) {
                    maxProfit = prices[i] - cheapest;
                }
            }
        }
        
        return maxProfit;
    }
};
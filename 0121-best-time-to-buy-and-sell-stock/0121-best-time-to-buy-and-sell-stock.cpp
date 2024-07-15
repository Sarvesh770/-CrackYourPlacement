class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int curr_min = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            curr_min = min(curr_min,prices[i]);
            max_profit = max(max_profit,prices[i]-curr_min);
        }
        return max_profit;

    }
};
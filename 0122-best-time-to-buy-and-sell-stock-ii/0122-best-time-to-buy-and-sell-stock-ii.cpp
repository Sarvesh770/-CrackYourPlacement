class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int cp = INT_MAX;
       //int sp = INT_MIN;
       int n = prices.size();
       int profit = 0;
       for(int i=0; i<n; i++){
        if(cp == INT_MAX || cp > prices[i]){
            cp = prices[i];
        }else{
            profit += prices[i]-cp;
            cp = prices[i];
        }
       } 
       return profit;
    }
};
class Solution {
    int solve(int ind, int tranNo, vector<int>&prices, int n,int k,vector<vector<int>>&dp){
        if(ind==n || tranNo == 2*k)return 0;
        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
        
        if(tranNo%2 == 0){
            return dp[ind][tranNo] = max(-prices[ind]+solve(ind+1,tranNo+1,prices,n,k,dp),
                       solve(ind+1,tranNo,prices,n,k,dp));
        }
        return dp[ind][tranNo] = max(prices[ind]+solve(ind+1,tranNo+1,prices,n,k,dp),
                        solve(ind+1,tranNo,prices,n,k,dp));
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return solve(0,0,prices,n,k,dp);
    }
};
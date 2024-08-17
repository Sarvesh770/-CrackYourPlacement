class Solution {
    int mod = (int)1e9+7;
    int solve(vector<int>& nums,vector<vector<vector<int>>>&dp,int i,int prev1,int prev2){
        if(i == nums.size()) return 1;
        if(dp[i][prev1][prev2] != -1) return dp[i][prev1][prev2];

        int ans = 0;
        for(int val = 0; val <= nums[i]; val++){
            if(prev1 <= val && prev2 >= nums[i]-val){
                ans = (ans + solve(nums,dp,i+1,val,nums[i]-val))%mod;
            }
        }
        return dp[i][prev1][prev2] = ans;
    }
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(51,vector<int>(51,-1)));
        return solve(nums,dp,0,0,50);
    }
};
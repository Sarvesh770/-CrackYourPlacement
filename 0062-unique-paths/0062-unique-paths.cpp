class Solution {
private:
    int totalPaths(int n, int m,vector<vector<int>>&dp){
        if(n < 0 || m < 0) return 0;
        if(n == 0 && m == 0) return 1;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int left = totalPaths(n,m-1,dp);
        int up = totalPaths(n-1,m,dp);
        
        return dp[n][m] = left+up;
    }
public:
    int uniquePaths(int m, int n) {
        // left up
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return totalPaths(m-1,n-1,dp);
    }
};
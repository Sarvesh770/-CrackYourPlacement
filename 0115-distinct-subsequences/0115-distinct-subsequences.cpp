class Solution {
    /*int solve(int i,int j, string s, string t,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }*/
    /*int solve(int i,int j, string s, string t,vector<vector<int>>&dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i-1] == t[j-1]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }*/
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        //return solve(n-1,m-1,s,t,dp);
        //return solve(n,m,s,t,dp);
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
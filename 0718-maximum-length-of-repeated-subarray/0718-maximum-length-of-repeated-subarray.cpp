class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
                // if both character is same
				if (nums1[i - 1] == nums2[j - 1]) {
                   
					dp[i][j] = dp[i - 1][j - 1] + 1;
                    // record the max ans here
					ans = max(ans, dp[i][j]);
				} else {
                    
				}
			}
		}
		return ans;
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string y, string x) {
        // your code here
        int n = y.size();
        int m = x.size();
        int t[m+1][n+1];
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(x[i-1] == y[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }else{
                    t[i][j] = 0;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                ans = max(ans,t[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
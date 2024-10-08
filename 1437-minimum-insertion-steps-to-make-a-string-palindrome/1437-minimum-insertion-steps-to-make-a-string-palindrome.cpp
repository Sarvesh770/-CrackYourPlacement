class Solution {
public:
    int minInsertions(string s) {
        string x = s;
        reverse(s.begin(),s.end());
        string y = s;
        int m = x.size();
        int n = y.size(); 
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
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return (s.length()-t[m][n]);
    }
};
class Solution {
private:
    void dfs(int i,int j,int col,vector<vector<int>>&ans,vector<vector<int>>&vis,int iniCol,vector<vector<int>>& image){
        int delR[4] = {-1,0,1,0};
        int delC[4] = {0,1,0,-1};
        int n = image.size();
        int m = image[0].size();
        vis[i][j] = 1;
        ans[i][j] = col;
        for(int ind=0; ind<4; ind++){
            int r = i+delR[ind];
            int c = j+delC[ind];
            if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == iniCol && !vis[r][c]){
                dfs(r,c,col,ans,vis,iniCol,image);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        int initialCol = image[sr][sc];
        // vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>ans = image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(sr,sc,color,ans,vis,initialCol,image);
        return ans;
    }
};
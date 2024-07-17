class Solution {
    bool solve(int curr,int i,int j,vector<vector<char>>& board, string word,vector<vector<bool>>&vis){
        if(curr == word.length()-1) return true;
        if(i-1 >= 0 && board[i-1][j] == word[curr+1] && !vis[i-1][j]){
            vis[i-1][j] = true;
            bool ans = solve(curr+1,i-1,j,board,word,vis);
            if(ans) return true;
            vis[i-1][j] = false;
        }
        if(j-1 >= 0 && board[i][j-1] == word[curr+1] && !vis[i][j-1]){
            vis[i][j-1] = true;
            bool ans = solve(curr+1,i,j-1,board,word,vis);
            if(ans) return true;
            vis[i][j-1] = false;
        }
        if(i+1 < board.size() && board[i+1][j] == word[curr+1] && !vis[i+1][j]){
            vis[i+1][j] = true;
            bool ans = solve(curr+1,i+1,j,board,word,vis);
            if(ans) return true;
            vis[i+1][j] = false;
        }
        if(j+1 < board[0].size() && board[i][j+1] == word[curr+1] && !vis[i][j+1]){
            vis[i][j+1] = true;
            bool ans = solve(curr+1,i,j+1,board,word,vis);
            if(ans) return true;
            vis[i][j+1] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis[i][j] = true;
                if(board[i][j] == word[0] && solve(0,i,j,board,word,vis)){
                    return true;
                }
                vis[i][j] = false;
            }
        }
        return false;
    }
};
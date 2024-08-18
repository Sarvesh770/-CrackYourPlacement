//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool isSafe(int i,int j,int r,int c){
        if(i>=0&&i<r&&j>=0&&j<c)
        return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int r=grid.size();
        int c=grid[0].size();
        int time=0;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
            if(grid[i][j]==2)
            q.push({i,j});
        }
        q.push({-1,-1});
        while(!q.empty()){
            
            while(true){
            auto front=q.front();
            q.pop();
            int i=front.first,j=front.second;
            
            if(i==-1&&j==-1){

                time++;
                if(!q.empty())
                q.push({-1,-1});
                break;
            }
            
            if(isSafe(i+1,j,r,c)&&grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            
            if(isSafe(i,j+1,r,c)&&grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            
            if(isSafe(i-1,j,r,c)&&grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            
            if(isSafe(i,j-1,r,c)&&grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            
          }
            
        }
        
        for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        if(grid[i][j]==1)
        return -1;
        
        return time-1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
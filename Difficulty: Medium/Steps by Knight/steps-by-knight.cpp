//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   queue<pair<int,int>> q;
	   q.push({KnightPos[0],KnightPos[1]});
	   vector<vector<int>> visited(N+1,vector<int>(N+1,0));
	   int cnt=0;
	   while(!q.empty()){
	       int len=q.size();
	       for(int i=0;i<len;i++){
	           vector<vector<int>> moves={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{-2,1},{2,-1},{-2,-1}};
	           int r=q.front().first;
	           int c=q.front().second;
	           if(r==TargetPos[0] && c==TargetPos[1])return cnt;

	           q.pop();
	           for(int i=0;i<8;i++){
	               int nr=r+moves[i][0];
	               int nc=c+moves[i][1];
	               if(min(nr,nc)>=1 && nr<=N && nc<=N && visited[nr][nc]==0){
	                        visited[nr][nc]=1;
	                        q.push({nr,nc});
	               }
	           }
	       }
	       cnt++;
	   }
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
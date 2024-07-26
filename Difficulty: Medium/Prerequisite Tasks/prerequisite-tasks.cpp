//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkforcycles( int i ,vector<vector<int>>& adj ,vector<int>& visited ){
        visited[i] = 1 ;
        
        for( auto & it : adj[i]){
            if( visited[it] == 1){
                return true ;
            }
            else if(!visited[it]){
                bool cycle = checkforcycles( it ,adj ,  visited  );
                if(cycle){
                    return true ;
                }
            }
        }
        visited[i] = 2 ;
        return false ;
    }
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int> visited(N , 0 );
	    vector<vector<int>> adj(N) ;
	    for( int i = 0 ; i < P ; i ++){
	        auto pq = prerequisites[i] ;
	        adj[pq.first].push_back(pq.second) ;
	    }
	    for( int i  = 0 ; i < N ; i ++ ){
	        if(visited[i] != 2 ){
	            bool cycle = checkforcycles( i , adj , visited ) ;
	            if(cycle){
	                return false ;
	            }
	        }
	    }
	return true ;
	    
	    
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    bool detectCycle(int src,int par,vector<int>adj[],int vis[]){
        vis[src] = 1;
        /*queue<pair<int,int>>q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto child : adj[node]){
                if(!vis[child]){
                    q.push({child,node});
                    vis[child] = 1;
                }else if(vis[child] && child != parent){
                    return true;
                }
            }
        }
        return false;*/
        for(auto child:adj[src]){
            if(!vis[child]){
                if(detectCycle(child,src,adj,vis)) return true;
            }else if(vis[child] && child != par){
                return true;
            }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detectCycle(i,-1,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    vector<int> parent;
    vector<int> rank;
	int find(int u){
	    if(u == parent[u]){
	        return u;
	    }
	    return parent[u] = find(parent[u]);
	}
	void union_find(int x, int y){
	    int x_parent = find(x);
        int y_parent = find(y);
    
        if (x_parent == y_parent) 
            return;
    
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } 
        else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } 
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
	}
	
	int kruskal(vector<vector<int>>&adj){
	    int sum =0;
	    for(auto it:adj){
	        int u = it[0];
	        int v= it[1];
	        int wt = it[2];
	        
	        int parent_u = find(u);
	        int parent_v = find(v);
	        
	        if(parent_u!=parent_v){
	            union_find(u,v);
	            sum+=wt;
	        }
	    }
	    return sum;
	}
	bool static comp(vector<int>&a,vector<int>&b){
	    return (a[2]<b[2]);
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //creating parent vector for disjoint set to comppoare whihc component it belongs
        parent.resize(V);
        rank.resize(V, 0);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        
        //
        vector<vector<int>>edge_wt;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edge_wt.push_back({u,v,wt});
                
            }
        }
        
        sort(edge_wt.begin(),edge_wt.end(),comp);
        // sort(adj.begin(),adj.end(),comp);
        
        return kruskal(edge_wt);
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
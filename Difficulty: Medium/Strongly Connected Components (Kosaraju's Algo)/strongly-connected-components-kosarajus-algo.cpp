//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    void dfs(vector<vector<int>>& adj,vector<int>& vis,int node,stack<int>& st)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(adj,vis,it,st);
	        }
	    }
	    st.push(node);
	}
	public:
		void dfs2(vector<int>adj[],vector<int>& vis,int node)
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs2(adj,vis,it);
	        }
	    }
	}
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
           
                if(!vis[i])
                {
                    dfs(adj,vis,i,st);
                }
            
        }
        vector<int> adjT[V];
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
        int c=0;
        while(!st.empty())
        {
            int top=st.top();
            st.pop();
            if(!vis[top])
            {
                c++;
                dfs2(adjT,vis,top);
            }
        }
        return c;
            
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
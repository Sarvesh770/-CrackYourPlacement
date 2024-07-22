class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        vector<int>dist(n,1e9);
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dist[src] = 0;
        pq.push({0,{src,0}});
        // {stops,{node,dist}}
        
        while(!pq.empty()){
            auto it = pq.top();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            pq.pop();
            
            if(stops > k) continue;
            
            for(auto it:adj[node]){
                int adjNode = it.first;
                int edgWt = it.second;
                if(cost + edgWt < dist[adjNode] && stops <= k){
                    dist[adjNode] = cost + edgWt;
                    pq.push({stops+1,{adjNode,cost+edgWt}});
                }
            }
        }
        
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
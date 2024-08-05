class DisjointSet{
    public:
        vector<int> parent, size;
        DisjointSet (int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<=n; i++) parent[i] = i;
        }

        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        bool findParEqual (int u, int v){
            return findUPar(u)==findUPar(v);
        }
        void unionBySize (int u, int v){
            int ulp_u = findUPar(u), ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<vector<int>> ans;
        for(auto it: edges){
            if(ds.findParEqual(it[0], it[1])) ans.push_back(it);
            ds.unionBySize(it[0], it[1]);
        }
        return ans.back();
    }
};
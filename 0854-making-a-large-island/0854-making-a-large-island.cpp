class Solution {
public:
    int dfs(vector<vector<int>>& grid, pair<int,int> p, int idx){
        stack<pair<int,int>> s;
        s.push(p);
        int area=0,n=grid.size();
        while(!s.empty()){
            pair<int,int> x=s.top();
            s.pop();
            int i=x.first,j=x.second;
            if(v[i][j]) continue;
            // else{
            v[i][j]=true;
            ++area;
            grid[i][j]=idx;
            if(i>0 && grid[i-1][j]==1 && !v[i-1][j]) s.push({i-1,j});
            if(j>0 && grid[i][j-1]==1 && !v[i][j-1]) s.push({i,j-1});
            if(i<n-1 && grid[i+1][j]==1 && !v[i+1][j]) s.push({i+1,j});
            if(j<n-1 && grid[i][j+1]==1 && !v[i][j+1]) s.push({i,j+1});
            // }
        }
        return area;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int> area;
        area[0]=0;

        int idx=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !v[i][j]){
                    area[idx]=dfs(grid,{i,j},idx);
                    ++idx;
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,area[grid[i][j]]);
                if(grid[i][j]==0){
                    set<int> s;
                    int ar=1;
                    if(i>0) s.insert(grid[i-1][j]);
                    if(j>0) s.insert(grid[i][j-1]);
                    if(i<n-1) s.insert(grid[i+1][j]);
                    if(j<n-1) s.insert(grid[i][j+1]);

                    for(auto idx:s) ar+=area[idx];
                    ans=max(ans,ar);
                }
            }
        }
        return ans;
    }
    bool v[501][501]={{0}};
};
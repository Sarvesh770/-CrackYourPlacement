class Solution {
public:
    typedef pair<int,pair<int,int>>pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pi>pq;
        for(int i=0; i<points.size(); i++){
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(pq.size()){
            pair<int,int> temp = pq.top().second;
            pq.pop();
            vector<int>v(2,0);
            v[0] = temp.first;
            v[1] = temp.second;
            ans.push_back(v);
        }
        return ans;
    }
};
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int max_reach = startFuel;
        priority_queue<int>pq;
        
        int cnt = 0; 
        int index = 0;
        
        while(max_reach < target){
            while(index < stations.size() && stations[index][0] <= max_reach){
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()) return -1;
            max_reach += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
        /*int n = stations.size();
        if(target-startFuel <= 0) return 0;
        if(n>0 && startFuel-stations[0][0] < 0) return -1;
        
        priority_queue<pair<int,int>>pq;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            target -= startFuel;
            if(target <= 0) return cnt;
            startFuel -= stations[i][0];
            pq.push({stations[i][1],stations[i][0]});
            if(startFuel <= 0 && pq.size()>0){
                startFuel += pq.top().first;
                pq.pop();
                cnt++;
            }else if(startFuel <= 0 && pq.size()==0){
                return -1;
            }
        }
        return -1;*/
    }
};
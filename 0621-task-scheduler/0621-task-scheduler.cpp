class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto t:tasks){
            mp[t]++;
        }
        priority_queue<int>pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int ans = 0;
        while(!pq.empty()){
            int timer = 0;
            vector<int>temp;
            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    timer++;
                }    
            }
            for(auto it:temp){
                if(it) pq.push(it);
            }
            ans += pq.empty() ? timer:n+1;
        }
        return ans;
    }
};
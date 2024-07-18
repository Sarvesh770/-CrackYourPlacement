class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // int i;
        // int n = nums.size();
        // for(i=0; i<=(n-k); i++){
        //     pq.push({nums[i],i});
        // }
        // vector<int>ans;
        // ans.push_back(pq.top().first);
        // int last_used = pq.top().second;
        // pq.pop();
        // while(ans.size() != k){
        //     if(i<n){
        //         pq.push({nums[i],i});
        //         i++;
        //     }
        //     if(pq.top().second < last_used){
        //         pq.pop();
        //     }else{
        //         ans.push_back(pq.top().first);
        //         last_used = pq.top().second;
        //         pq.pop();
        //     }
        // }
        // return ans;
        vector<int>ans(k);
        stack<int>s;
        int d= nums.size()-k;
        for(int i=0; i<nums.size();i++){
            while(!s.empty() && s.top() > nums[i] && d>0){
                s.pop();
                d--;
            }
            s.push(nums[i]);
        }
        while(s.size() > k){
            s.pop();
        }
        for(int i=k-1; i>=0; i--){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};
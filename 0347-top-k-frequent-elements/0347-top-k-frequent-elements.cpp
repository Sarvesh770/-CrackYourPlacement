class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(auto i:m){
            p.push({i.second,i.first});
            if(p.size() > k){
                p.pop();
            }
        }
        while(p.size()>0){
            pair<int,int> temp = p.top();
            p.pop();
            ans.push_back(temp.second);
        }
        return ans;
    }
};
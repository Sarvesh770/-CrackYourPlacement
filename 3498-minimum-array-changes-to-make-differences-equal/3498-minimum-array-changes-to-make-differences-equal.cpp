class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int>limit;
        int n = nums.size();
        int s = 0;
        int e = n-1;
        unordered_map<int,int>mp;
        while(s<e){
            int mn = min(nums[s],nums[e]);
            int mx = max(nums[s],nums[e]);
            mp[mx-mn]++;
            limit.push_back(max(k-mn,mx));
            s++;
            e--;
        }
        sort(limit.begin(),limit.end());
        int ans = n/2;
        for(auto it:mp){
            int diff = it.first;
            int cntDiff = it.second;
            int extras = lower_bound(limit.begin(),limit.end(),diff)-limit.begin();
            extras += (n/2-cntDiff);
            ans = min(ans,extras);
        }
        return ans;
    }
};
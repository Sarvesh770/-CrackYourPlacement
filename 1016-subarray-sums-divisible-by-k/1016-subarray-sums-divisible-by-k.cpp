class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // vector<int> v(k,0);
        // int curr_sum = 0;
        // v[0]++;
        // int ans = 0;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     curr_sum = (curr_sum + nums[i]%k + k)%k;
        //     ans += v[curr_sum];
        //     v[curr_sum]++;
        // }    
        // return ans;
        map<int,int>mp;
        int sum = 0;
        mp[0]++;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            sum = (sum + nums[i]%k + k)%k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};
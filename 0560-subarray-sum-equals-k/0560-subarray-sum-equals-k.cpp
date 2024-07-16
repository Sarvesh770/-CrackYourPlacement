class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        unordered_map<int,int>mp;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum == k){
                cnt++;
            }
            int remaining = sum-k;
            if(mp.find(remaining) != mp.end()){
                cnt += mp[remaining];
            }
            if(mp.find(sum) == mp.end()){
                mp[sum]=1;
            }else{
                mp[sum]++;
            }
        }
        return cnt;
    }
};
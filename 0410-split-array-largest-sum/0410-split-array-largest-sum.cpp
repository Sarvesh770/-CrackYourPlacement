class Solution {
public:
    bool isPossible(vector<int>& nums,int m, int k){
        int curr_cnt = 1;
        long long sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(sum+nums[i] <= m){
                sum += nums[i];
            }else{
                sum = nums[i];
                curr_cnt++;
            }
        }
        return curr_cnt <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums[0];

        long long low = *max_element(nums.begin(),nums.end());
        long long high = accumulate(nums.begin(),nums.end(),0);

        while(low <= high){
            long long mid = low + (high-low)/2;
            if(isPossible(nums,mid,k)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
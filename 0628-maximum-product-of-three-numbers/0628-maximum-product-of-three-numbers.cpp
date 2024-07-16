class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n==3) return nums[2]*nums[1]*nums[0];
        if(nums[0]>0){
            return nums[n-1]*nums[n-2]*nums[n-3];
        }else if(nums[0]<0){
            return max(nums[n-1]*nums[n-2]*nums[n-3],nums[n-1]*nums[1]*nums[0]);
        }else if(nums[0]==0){
            return (nums[n-1]*nums[n-2]*nums[n-3]);
        }
        return 0;
    }
};
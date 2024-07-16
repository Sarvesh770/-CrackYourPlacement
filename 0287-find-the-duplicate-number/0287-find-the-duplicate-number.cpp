class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int slow = nums[0];
        // int fast = nums[0];
        // do{
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        // }while(slow != fast);
        // fast = nums[0];
        // while(slow != fast){
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }
        // return slow;
        for(auto n:nums){
            n = abs(n);
            if(nums[n-1] > 0) nums[n-1] *= -1;
            else return n;
        }
        return -1;
    }
};
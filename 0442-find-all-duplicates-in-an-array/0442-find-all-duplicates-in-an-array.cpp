class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int>dup;
       for(auto n:nums){
        n = abs(n);
        if(nums[n-1] > 0) nums[n-1] *= -1;
        else dup.push_back(n);
       } 
       return dup;
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=-1,j=0;
        for(int ind=0; ind<nums.size(); ind++){
            if(nums[ind] == 0){
                i = ind;
                j = ind+1;
                break;
            }
        }
        if(i == -1 || j == nums.size()) return;
        while(j<nums.size()){
            if(nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }
};
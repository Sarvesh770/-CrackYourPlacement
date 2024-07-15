class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = INT_MIN;
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(el == INT_MIN || cnt == 0){
                el = nums[i];
                cnt = 1;
            }else if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
            }
        }
        return el;
    }    
};    
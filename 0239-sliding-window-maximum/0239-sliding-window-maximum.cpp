class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        list<int>ls;
        int i = 0, j = 0;
        while(j<nums.size()){
            while(ls.back() < nums[j] && ls.size()>0){
                ls.pop_back();
            }
            ls.push_back(nums[j]);
            if(j-i+1 < k){
                j++;
            }else if(j-i+1 == k){
                v.push_back(ls.front());
                if(nums[i] == ls.front()){
                    ls.pop_front();
                }
                i++;
                j++;
            }
        }
        return v;
    }
};
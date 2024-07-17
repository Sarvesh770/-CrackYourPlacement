class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>>st;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                set<long long>hashset;
                for(int k=j+1; k<nums.size(); k++){
                    long long sum = target-(nums[i]);
                    sum -= nums[j];
                    sum -= nums[k];
                    
                    if(hashset.find(sum) != hashset.end()){
                        vector<int>temp = {nums[i],nums[j],nums[k],(int)sum};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
                
            }
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};
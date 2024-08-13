/*void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int index){
    if(index == nums.size()){
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(nums[index]);
    solve(nums,ans,temp,index+1);
    temp.pop_back();
    solve(nums,ans,temp,index+1);
}*/

class Solution {
    
    void solve(vector<int>nums,vector<vector<int>>&res,vector<int>&ans){
        if(nums.size()==0){
            res.push_back(ans);
            return;
        }
        vector<int>temp1=ans;
        vector<int>temp2=ans;
        temp2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,res,temp1);
        solve(nums,res,temp2);
        
        return;
    }
   
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*vector<vector<int>>ans;
        vector<int>temp;
        temp.clear();
        ans.clear();
        solve(nums,ans,temp,0);
        return ans;*/
        
        vector<vector<int>>res;
        vector<int>ans;
        solve(nums,res,ans);
        return res;
        
    }
};
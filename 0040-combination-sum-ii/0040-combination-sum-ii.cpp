class Solution {
    void allCombination(int ind,vector<int>& candidates,vector<int>&ds,vector<vector<int>>&ans,int target){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<candidates.size(); i++){
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            allCombination(i+1,candidates,ds,ans,target-candidates[i]);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        allCombination(0,candidates,ds,ans,target);
        return ans;
    }
};
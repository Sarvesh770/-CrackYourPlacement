class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<int>diff(n,0);
        for(int i=0; i<n; i++) diff[i] = nums[i]-target[i];
        long long ans = 0, incOp = 0, decOp = 0;

        for(int i=0; i<n; i++){
            if(diff[i] > 0){
                if(incOp < diff[i]){
                    int extra = diff[i]-incOp;
                    ans += extra;
                }
                incOp = diff[i];
                decOp = 0;
            }else if(diff[i] < 0){
                if(decOp < -diff[i]){
                    int extra = -diff[i]-decOp;
                    ans += extra;
                }
                decOp = -diff[i];
                incOp = 0;
            }else{
                incOp = decOp = 0;
            }
        }
        return ans;
    }
};
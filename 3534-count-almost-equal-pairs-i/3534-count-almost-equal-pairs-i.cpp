class Solution {
public:
    bool check(int a,int b){
        if(a == b) return true;
        string n1 = to_string(a);
        string n2 = to_string(b);
        for(int i=0; i<n1.size(); i++){
            for(int j=i+1; j<n1.size(); j++){
                if(i == 0 && n1[j] == '0'){
                    swap(n1[i],n1[j]);
                    int k = 0;
                    while(n1[k] == '0'){
                        k++;
                    }
                    if(n1.substr(k) == n2) return true;
                    swap(n1[i],n1[j]);
                }
                swap(n1[i],n1[j]);
                if(n1 == n2) return true;
                swap(n1[i],n1[j]);
            }
        }
        for(int i=0; i<n2.size(); i++){
            for(int j=i+1; j<n2.size(); j++){
                if(i == 0 && n2[j] == '0'){
                    swap(n2[i],n2[j]);
                    int k = 0;
                    while(n2[k] == '0'){
                        k++;
                    }
                    if(n2.substr(k) == n1) return true;
                    swap(n2[i],n2[j]);
                }
                swap(n2[i],n2[j]);
                if(n1 == n2) return true;
                swap(n2[i],n2[j]);
            }
        }
        return false;
    }
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(check(nums[i],nums[j])){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
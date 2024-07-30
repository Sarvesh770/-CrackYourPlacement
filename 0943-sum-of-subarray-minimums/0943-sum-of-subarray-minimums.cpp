class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int>s1;
        vector<int> next_smaller(n),pre_smaller(n);
        for(int i=0; i<n; i++){
            next_smaller[i] = n-i-1;
            pre_smaller[i] = i;
        }
        for(int i=0; i<n; i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                next_smaller[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        while(!s1.empty()) s1.pop();
        for(int i=n-1; i>=0; i--){
            while(!s1.empty() && arr[s1.top()]>=arr[i]){
                pre_smaller[s1.top()] = s1.top()-i-1;
                s1.pop();
            }
            s1.push(i);
        }
        long long sum = 0;
        int mod = 1e9+7;
        for(int i=0; i<n; i++){
            sum += (arr[i]*1LL*(pre_smaller[i]+1)*(next_smaller[i]+1));
            sum %= mod;
        }
        return sum;
    }
};
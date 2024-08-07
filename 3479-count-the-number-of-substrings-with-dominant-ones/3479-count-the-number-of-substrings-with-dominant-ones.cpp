#include<bits/stdc++.h>
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        vector<int>prefix(n,0);
        for(int i=0; i<n; i++){
            if(i==0){
                if(s[i] == '1'){
                    prefix[i] = 1;
                }
            }else{
                if(s[i] == '1'){
                    prefix[i] = prefix[i-1]+1;
                }else{
                    prefix[i] = prefix[i-1];
                }
            } 
        }
        for(auto it:prefix){
            cout<<it<<" ";
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int ones = 0, zero = 0;
                if(i == 0) {
                    ones = prefix[j];
                }
                else {
                    ones = prefix[j]-prefix[i-1];
                }
                zero = j-i+1-ones;

                if(zero*zero <= ones){
                    ans++;
                    int temp = sqrt(ones);
                    if(temp > zero){
                        if(j+temp-zero >= n) {
                            ans += (n-1-j);
                        }
                        else {
                            ans += temp-zero;
                        }
                        j += (temp-zero);

                    }
                }else{
                    j += (zero*zero - ones - 1);
                }
            }
        }
        return ans;
    }
};
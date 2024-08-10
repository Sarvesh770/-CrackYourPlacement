class Solution {
public:
    int characterReplacement(string s, int k) {
        int char_cnt[26]={};
        int mx_len = 0, i = 0, j = 0;
        while(j<s.size()){
            char_cnt[s[j]-'A']++;
            while(j-i+1 - *max_element(char_cnt,char_cnt+26) > k){
                char_cnt[s[i]-'A']--;
                i++;
            }
            mx_len = max(mx_len,j-i+1);
            j++;
        }
        return mx_len;
    }
};
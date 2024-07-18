class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT_MAX;
        string s="";
        for(int i=0; i<strs.size(); i++){
            if(strs[i].size() < min_len){
                min_len = strs[i].size();
                s = strs[i];
            }
        }
        int max_len=0;
        bool flag = true;
        for(int i=0; i<min_len; i++){
            char to_check = s[i];
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i] != to_check){
                    flag = false;
                    max_len = i;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag){
            return s;
        }else{
            return s.substr(0,max_len);
        }
    }
};
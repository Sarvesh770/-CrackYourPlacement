class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int m=haystack.size();
        int n=needle.size();
        bool flag=true;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(haystack[i+j]==needle[j]){
                    flag=true;
                    continue;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag==true) return i;
        }
        return -1;
    }
};
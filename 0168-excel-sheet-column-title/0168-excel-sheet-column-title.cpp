class Solution {
public:
    string convertToTitle(int n) {
        string s="";
        while(n){
            char c=(n-1)%26 + 'A';
            s = c + s;
            n = (n-1)/26;
        }
        return s;
    }
};
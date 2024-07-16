class Solution {
public:
    string addBinary(string a, string b) {
        string s;
        int i=0;
        int m=a.size();
        int n=b.size();
        int carry=0;
        while(i<m || i<n || carry != 0){
            int x=0;
            if(i<m && a[m-i-1]=='1'){
                x=1;
            }
            int y=0;
            if(i<n && b[n-i-1]=='1'){
                y=1;
            }
            s=to_string((x+y+carry)%2)+s;
            carry=(x+y+carry)/2;
            i+=1;
        }
        return s;
    }
};
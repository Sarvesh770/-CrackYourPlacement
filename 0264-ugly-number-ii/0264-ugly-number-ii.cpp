class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0]=1;
        int i2 = 0, i3 = 0, i5 = 0;
        int f2 = 2, f3 = 3, f5 = 5;
        for(int i=1; i<n; i++){
            ugly[i] = min({f2,f3,f5});
            if(ugly[i] == f2) f2 = 2*ugly[++i2];
            if(ugly[i] == f3) f3 = 3*ugly[++i3];
            if(ugly[i] == f5) f5 = 5*ugly[++i5];
        }
        return ugly[n-1];
    }
};
class Solution {
public:
    long long minimumCost(int mGiven, int nGiven, vector<int>& horizontalCut, vector<int>& verticalCut) {
        long long ans = 0;
        int hSection = 1, vSection = 1, i = 0, j= 0;
        int n = horizontalCut.size(); 
        int m = verticalCut.size();
        sort(horizontalCut.rbegin(),horizontalCut.rend());
        sort(verticalCut.rbegin(),verticalCut.rend());

        while(i<n && j < m){
            if(horizontalCut[i] >= verticalCut[j]){
                ans += vSection*horizontalCut[i];
                hSection++;
                i++;
            }else{
                ans += hSection*verticalCut[j];
                vSection++;
                j++;
            }
        }
        while(i<n){
            ans += vSection*horizontalCut[i];
            hSection++;
            i++;
        }
        while(j<m){
            ans += hSection*verticalCut[j];
            vSection++;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int area;
        int maxArea = 0;
        while(start < end){
            area = min(height[start],height[end])*(end-start);
            if(area > maxArea){
                maxArea = area;
            }
            if(min(height[start],height[end]) == height[start]){
                start++;
            }else{
                end--;
            }
        }
        return maxArea;
    }
};
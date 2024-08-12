class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt = 0;
        int previous = 0;
        int n = intervals.size();
        
        for(int current=1; current<n; current++){
            
            // [1 5] [3,6] first overlapping case
            // [1,5] [2,3] second overlapping case
            
            if(intervals[current][0] < intervals[previous][1]){
                cnt++;
                if(intervals[current][1] <= intervals[previous][1]){
                    previous = current;
                }
            }else{
                // [1,5] [7,9] non overlapping case
                previous = current;
            }
        }
        return cnt;
    }
};
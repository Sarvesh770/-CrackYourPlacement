class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        bool can_reach = true;
        if(heights.size() == 1) return 0;
        int n = heights.size();
        for(int i=1; i<n; i++){
            int diff = heights[i]-heights[i-1];
            if(diff > 0){
                bricks -= diff;
                pq.push(diff);
                if(bricks < 0){
                    if(ladders <= 0) return i-1;
                    int getbricks = pq.top();
                    bricks += getbricks;
                    ladders--;
                    pq.pop();
                }
            }
        }
        return n-1;
    }
};
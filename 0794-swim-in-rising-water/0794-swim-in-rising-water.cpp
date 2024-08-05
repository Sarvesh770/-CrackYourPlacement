class Solution {
public:
    // Directions for moving up, right, down, and left
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    // Function to check if a position is within grid bounds
    bool isValid(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Vector to store the minimum time to reach each cell
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        
        // Priority queue to process cells in ascending order of height
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Start from the top-left corner (0,0) with initial height grid[0][0]
        pq.push({grid[0][0], {0, 0}});
        minTime[0][0] = grid[0][0];
        int maxHeight = 0;
        
        // Process the priority queue
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int height = current.first;
            int currX = current.second.first;
            int currY = current.second.second;
            maxHeight = max(height, maxHeight);
            
            // If reached the bottom-right corner, return the maximum height encountered
            if (currX == n - 1 && currY == n - 1) {
                return maxHeight;
            }
            
            // Explore all four possible directions
            for (int i = 0; i < 4; i++) {
                int nextX = currX + directions[i].first;
                int nextY = currY + directions[i].second;
                
                // Check if the new position is valid
                if (isValid(nextX, nextY, n)) {
                    int newHeight = max(height, grid[nextX][nextY]);
                    
                    // If a shorter path to next cell is found, update the minimum time and push to the queue
                    if (newHeight < minTime[nextX][nextY]) {
                        minTime[nextX][nextY] = newHeight;
                        pq.push({newHeight, {nextX, nextY}});
                    }
                }
            }
        }
        
        return -1;  // In case no path is found (though the problem guarantees there is one)
    }
};
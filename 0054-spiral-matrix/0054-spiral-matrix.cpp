class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        
        int top = 0 , down = n-1;
        int left = 0 , right = m-1;
        int direction = 0; // 0 means we print from left to right and 1 means vice versa
        while(left<=right && top <= down){
            if(direction == 0){
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }else if(direction == 1){
                for(int i=top; i<=down; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }else if(direction == 2){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }else if(direction == 3){
                for(int i=down; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        }
        return ans;
    }
};
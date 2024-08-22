class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        priority_queue<vector<int>>pq;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minh;

        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){
                if(minh.size() < 3){
                    minh.push({board[i][j],i,j});
                }else if(board[i][j] > minh.top()[0]){
                    minh.pop();
                    minh.push({board[i][j],i,j});
                }
            }
            while(!minh.empty()){
                pq.push(minh.top());
                minh.pop();
            }
        }
        vector<vector<int>>vec;
        while(!pq.empty()){
            vec.push_back(pq.top());
            pq.pop();
        }
        long long ans = LLONG_MIN;
        int sz = vec.size();

        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                if(vec[i][1] == vec[j][1] || vec[i][2] == vec[j][2]) continue;
                for(int k=j+1; k<sz; k++){
                    if(vec[i][1] == vec[k][1] || vec[i][2] == vec[k][2] || vec[j][1] == vec[k][1] || vec[j][2] == vec[k][2]) continue;

                    long long val = (long long)vec[i][0]+vec[j][0]+vec[k][0];
                    ans = max(ans,val);
                    break;
                }
            }
        }
        return ans;
    }
};
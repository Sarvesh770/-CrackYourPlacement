class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n = cardPoints.size();
        int maxSum = 0;
        for(int i=0; i<k; i++){
            sum += cardPoints[i];
            //cout<<sum<<endl;
            if(sum > maxSum) maxSum = sum;
        }
        int temp = k-1;
        for(int i=n-1; i>=(n-k); i--){
            sum += cardPoints[i];
            sum -= cardPoints[temp--];
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};
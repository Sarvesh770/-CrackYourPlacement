class Solution {
    int merge(vector<int>&arr,int low,int mid,int high){
        vector<int>temp;
        int cnt = 0;
        int left = low, right = mid+1;
        int r = mid+1;
        for(int i=low; i<=mid; i++){
            while(r <= high && (long long)arr[i] > 2*(long long)arr[r]){
                r++;
            }
            cnt += (r-(mid+1));
        }
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= high){
            temp.push_back(arr[right++]);
        }
        for(int i=low; i<=high; i++){
            arr[i] = temp[i-low];
        }
        return cnt;
    }
    int mergeSort(vector<int>&arr,int low,int high){
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + (high-low)/2;
        cnt += mergeSort(arr,low,mid);
        cnt += mergeSort(arr,mid+1,high);
        cnt += merge(arr,low,mid,high);
        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};
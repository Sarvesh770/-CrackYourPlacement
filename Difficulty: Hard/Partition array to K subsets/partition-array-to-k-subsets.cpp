//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool solve(int i,int k,int subsetSum,int used,vector<int>& nums,int target,unordered_map<int,bool> &mp){
        if(k==0) return true;
        int key=used*20+k;
        if(mp.find(key)!=mp.end()) return mp[key];
        if(subsetSum==target) return mp[key]=solve(0,k-1,0,used,nums,target,mp);
        for(int j=i;j<nums.size();j++){
            if(used&(1<<j) || subsetSum+nums[j]>target) continue;
            if(solve(j+1,k,subsetSum+nums[j],used|(1<<j),nums,target,mp)) return mp[key]=true;
        }
        return mp[key]=false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         vector<int> nums;
         for(int i=0;i<n;i++) nums.push_back(a[i]);
         int sum=0;
        for(int i: nums) sum+=i;
        if(sum%k) return false;
        sum=sum/k;
        sort(nums.rbegin(),nums.rend());
        unordered_map<int,bool> mp;
        int used=0;
        return solve(0,k,0,used,nums,sum,mp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends
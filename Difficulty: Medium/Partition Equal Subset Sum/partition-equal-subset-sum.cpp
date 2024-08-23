//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subsetsum(int i,int sum,int arr[],vector<vector<int>>& t){
        if(sum==0) return true;
        if(i<0||sum<0) return false;
        
        if(t[i][sum]!=-1){
            return t[i][sum];
        }
        bool y=subsetsum(i - 1, sum - arr[i], arr, t);
        bool n =subsetsum(i - 1, sum, arr, t);
       
        return (t[i][sum] = y || n );

    }
    
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        
        if(sum%2==1){
            return false;
        } 
        sum = sum / 2;

        vector<vector<int>> t(N, vector<int>(sum + 1, -1));
        return subsetsum(N - 1, sum, arr, t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
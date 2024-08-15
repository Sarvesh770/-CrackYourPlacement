//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void permutation(int i, int n,vector<int>p, vector<vector<int>>&ans, vector<int>arr, bool v[]){
        if(i == n ){
            ans.push_back(p);
            return;
        }
        
        for(int j =0; j<n; j++){
            
            if(v[j] == false){
                
                if(j>0){
                    if(arr[j]!= arr[j-1] || v[j-1] == true){
                        p.push_back(arr[j]);
                        v[j] = true;
                        permutation(i+1, n,p,ans,arr,v);
                        v[j] = false;
                        p.pop_back();
                    }
                    
                }else{
                    p.push_back(arr[j]);
                    v[j] = true;
                    permutation(i+1,n,p,ans,arr,v);
                    v[j] = false;
                    p.pop_back();
                }
                
            }
            
        }
        
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        vector<vector<int>> ans;
        vector<int>p;
        bool v[n];
        
        for(auto x: v){
            x = false;
        }
        
        sort(arr.begin(), arr.end());
        
        permutation(0, n, p, ans, arr, v);
    
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
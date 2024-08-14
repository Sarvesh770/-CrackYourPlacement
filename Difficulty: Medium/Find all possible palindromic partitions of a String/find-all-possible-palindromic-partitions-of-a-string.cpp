//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool isPalindrome(string s)
    {
        string temp = s;
        reverse(temp.begin(),temp.end());
        return (s == temp);
    }
    void partitionRec(int idx,string s,vector<string> &ds,vector<vector<string>> &ans)
    {
        if(idx >= s.length())
        {
            ans.push_back(ds);
            return;
        }
        
        for(int i = idx; i < s.length(); i++)
        {
            string str = s.substr(idx,i-idx+1);
            if(isPalindrome(str))
            {
                ds.push_back(str);
                partitionRec(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<string> ds;
        vector<vector<string>> ans;
        partitionRec(0,s,ds,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
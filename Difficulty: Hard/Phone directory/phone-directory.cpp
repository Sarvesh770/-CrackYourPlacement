//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    class trie_node{
        public:
        trie_node* child[26];
        trie_node(){
            for(int i = 0;i < 26;i++)child[i] = NULL;
        }
        bool isleaf = false;
    };
    void insert(trie_node * root,string vec,int i){
        if(i == vec.size()){
            root->isleaf = true;
            return;
        }
        if(root->child[vec[i]-'a']){
            insert(root->child[vec[i]-'a'],vec,i+1);
        }
        else{
            root->child[vec[i]-'a'] = new trie_node();
            insert(root->child[vec[i]-'a'],vec,i+1);
        }
    }
    
    void search(trie_node * root,string vec,int i,string str,vector<string> &ans){
        if(root->isleaf == true and i >= vec.size()){
            ans.push_back(str);
        }
        if(i < vec.size() and root->child[vec[i]-'a']){
            search(root->child[vec[i]-'a'],vec,i+1,str+vec[i],ans);
        }
        else if(i == vec.size()){
            for(int j = 0;j < 26;j++){
                if(root->child[j]){
                    search(root->child[j],vec,i,str+char(j+'a'),ans);
                }
            }
        }
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        trie_node * root = new trie_node();
        for(int i = 0;i < n;i++){
            insert(root,contact[i],0);
        }
        vector<vector<string>> ans;
        string str = "";
        for(int i = 0;i < s.size();i++){
            str += s[i];
            vector<string> vec;
            search(root,str,0,"",vec);
            if(!vec.empty())ans.push_back(vec);
            else{
                vec.push_back("0");
                ans.push_back(vec);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
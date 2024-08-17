//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string st)
    {
        // Your code here
        stack<int>s;
        for(int i=0;i<st.length();i++){
            char c=st[i];
            if(c>='0'&&c<='9'){
                s.push(c-'0');
            }else{
                int first=s.top();s.pop();
                int second=s.top();s.pop();
                if(c=='+')s.push(second+first);
                else if(c=='-')s.push(second-first);
                else if(c=='*')s.push(second*first);
                else if(c=='/')s.push(second/first);
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
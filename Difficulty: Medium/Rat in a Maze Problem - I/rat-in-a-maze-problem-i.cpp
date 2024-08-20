//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> dx = { -1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<char> dir = {'U', 'R', 'D', 'L'};
    bool isOk(int r, int c, int n)
    {
        if(r < 0 || r >= n || c < 0 || c >= n)
            return false;
        return true;
    }
    void recur(int r, int c, int n, vector<vector<int>>& mat, string& curr, 
        vector<vector<bool>>& visited, vector<string>& ans)
    {
        if(r == n - 1 && c == n - 1)
        {
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            int did = r + dx[i];
            int djd = c + dy[i];
            if(isOk(did, djd, n) && !visited[did][djd] && mat[did][djd] != 0)
            {
                visited[did][djd] = true;
                curr = curr + dir[i];
                recur(did, djd, n, mat, curr, visited, ans);
                visited[did][djd] = false;
                curr.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        string curr = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<string> ans;
        if(mat[0][0] == 1) visited[0][0] = true;
        else return {};
        recur(0, 0, n, mat, curr, visited, ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
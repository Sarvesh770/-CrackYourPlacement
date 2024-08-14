//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isCheck(bool graph[101][101], int n, vector<int> &color, int i, int c){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == true && color[j] == c){
                return false;
            }
        }
        return true;
    }
    
    
    void travel(bool graph[101][101], int m, int n, bool &check, vector<int> &color, int i){
        if(i == n){
            check = true;
            return;
        }
        for(int c = 1; c <= m; c++){
            if(isCheck(graph, n, color, i, c)){
                color[i] = c;
                travel(graph, m, n, check, color, i + 1);
                if(check){
                    return;
                }
                color[i] = 0;
            }
        }
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color (n, 0);
        bool check = false;
        travel(graph, m, n, check, color, 0);
        return check;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
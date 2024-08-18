//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int d = 0; // Deficit
        int b = 0; // Balance
        int s = 0; // Starting point
        
        for(int i = 0; i < n; i++) {
            b += p[i].petrol - p[i].distance;
            
            // If balance is negative, we cannot start from this or previous points
            if(b < 0) {
                d += b; // Accumulate deficit
                s = i + 1; // Set the next point as the starting point
                b = 0; // Reset balance
            }
        }
        
        // If the total balance (including deficit) is non-negative, return starting point
        return (b + d >= 0) ? s : -1;
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
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(vector<int>& wt, vector<int>& val,int W,vector<vector<int>>&dp,int i){
        int n=val.size();
        if(i==n || W<0){
            return 0;
        }
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        int take=0;
        int nottake=solve(wt,val,W,dp,i+1);
        if(W-wt[i]>=0){
            take=val[i]+solve(wt,val,W-wt[i],dp,i+1);
        }
        return max(take,nottake);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(wt,val,W,dp,0);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
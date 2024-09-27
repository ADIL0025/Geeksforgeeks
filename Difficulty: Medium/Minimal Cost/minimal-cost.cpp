//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    int solve(int idx, vector<int>& arr, int k, vector<int>& dp) {
        if(idx == arr.size()-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        for(int i=idx+1; i<min(idx+k+1, (int)arr.size()); ++i) {
            ans = min(ans, abs(arr[idx] - arr[i]) + solve(i, arr, k, dp));
        }
        return dp[idx] = ans;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = (int)arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
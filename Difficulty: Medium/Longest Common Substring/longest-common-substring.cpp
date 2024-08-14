//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int res = 0;
    vector<vector<int>> dp;
    
    int solve(string& str1, string& str2, int i, int j) {
        if(i >= str1.size() || j >= str2.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(str1[i] == str2[j]) ans = 1 + solve(str1, str2, i + 1, j + 1);
        
        solve(str1, str2, i, j + 1);
        solve(str1, str2, i + 1, j);
        
        res = max(res, ans);
        
        return dp[i][j] = ans;
    }
    
    int tab(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int ans = 0;
                if(s1[i - 1] == s2[j - 1]) ans = 1 + dp[i - 1][j - 1];
                else ans = 0;
                
                dp[i][j] = ans;
                res = max(res, ans);
            }
        }
        
    }
  
    int longestCommonSubstr(string str1, string str2) {
        // dp = vector<vector<int>> (str1.size() + 1, vector<int> (str2.size() + 1, -1));
    
        // solve(str1, str2, 0, 0);
        
        tab(str1, str2);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
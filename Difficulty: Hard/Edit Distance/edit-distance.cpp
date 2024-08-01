//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>dp;
    int helper(string &str1, string &str2, int i, int j){
        if(i<0 and j<0)return 0;
        if( j<0 )return i+1;
        if(i<0 )return j+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(str1[i]==str2[j])return dp[i][j]=helper(str1,str2,i-1,j-1);
        int i1=1+helper(str1,str2,i,j-1);
        int i2=1+helper(str1,str2,i-1,j);
        int i3=1+helper(str1,str2,i-1,j-1);
        return dp[i][j]=min({i1,i2,i3});
    }
    int editDistance(string str1, string str2) {
        // Code here
        int n=str1.size(),m=str2.size();
        dp.resize(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=i;
        for(int j=1;j<=m;j++)dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1])dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
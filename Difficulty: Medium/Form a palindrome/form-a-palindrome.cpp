//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int sol(int i,int j,int n,int m,string &a,string &b,vector<vector<int>> &dp){
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]){
        return dp[i][j]=1+sol(i+1,j+1,n,m,a,b,dp);
    }
    else{
        return dp[i][j]=0+max(sol(i+1,j,n,m,a,b,dp),sol(i,j+1,n,m,a,b,dp));
    }
}
int solve(string A) {
    int n=A.size();
    string B=A;
    reverse(B.begin(),B.end());
    int m=B.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return sol(0,0,n,m,A,B,dp);
}
    int countMin(string str){
    //complete the function here
    return str.size()-solve(str);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
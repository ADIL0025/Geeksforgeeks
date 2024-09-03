//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
		

	public:
	int helper(int i, int j, string &str1, string &str2, vector<vector<int>> &dp){
	    if(i == -1 && j == -1)
	        return 0;
	    if(i>=0 and j<0)
	        return 1+i;
	    if(j>=0 and i<0)
	        return 1+j;
	    if(dp[i][j] != -1)
	        return dp[i][j];
        if(str1[i] == str2[j])
            return dp[i][j] = helper(i-1, j-1, str1, str2, dp);
        else
            return dp[i][j] = 1 + min(helper(i-1, j, str1, str2, dp), helper(i, j-1, str1, str2, dp));
	}
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	     int n = str1.size();
	    int m = str2.size();
	    vector<vector<int>> dp(n, vector<int> (m, -1));
	    return helper(n-1, m-1, str1, str2, dp);
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
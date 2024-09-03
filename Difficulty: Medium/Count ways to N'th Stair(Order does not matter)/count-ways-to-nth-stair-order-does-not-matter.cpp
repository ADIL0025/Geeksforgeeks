//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
		int nthStair(int n){
		    //  Code here
		    if(n==1) return 1;
		    if(n==2) return 2;
		    vector<int> dp(n+1, 0);
		    dp[1]=1;
		    dp[2]=2;
		    for(int i=3;i<=n;i++){
		        dp[i]=dp[i-1];
		        if(!(i&1)) dp[i]++;
		    }
		    return dp[n];
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
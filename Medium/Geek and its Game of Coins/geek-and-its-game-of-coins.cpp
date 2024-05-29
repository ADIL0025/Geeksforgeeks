//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int findWinner(int n, int x, int y) {
        vector<bool> dp(n+1, false);

       
        dp[0] = false; 

        for (int i = 1; i <= n; i++) {

            bool option1 = (i - 1 >= 0) ? !dp[i - 1] : false;

           
            bool option2 = (i - x >= 0) ? !dp[i - x] : false;

            
            bool option3 = (i - y >= 0) ? !dp[i - y] : false;

            
            dp[i] = option1 || option2 || option3;
        }

        
        return dp[n] ? 1 : 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends
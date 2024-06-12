//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int cnt = 0;
        for(int i=0; i<=n; i++)
        {
            if(cf(i))
            {
                cnt++;
            }
        }
        return cnt;
    }
    bool cf(int s)
    {
        while(s > 0)
        {
            if(s%10 == 4)
            {
                return true;
            }
            s /= 10;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends
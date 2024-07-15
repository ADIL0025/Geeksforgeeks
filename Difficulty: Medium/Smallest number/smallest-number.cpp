//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
         if (d == 1 && s < 10) return to_string(s);
        if(s>9*d) return "-1";
        int val = 9;
        string st;
        while (d > 1 && val > 0) {
            if (val <s) {
                st += to_string(val);
                s -= val;
                d--;
            } else {
                val--;
            }
        }
        if(s>0) st+=to_string(s);
        string ans;
        ans+=st[st.size()-1];
        if(d>0){
            while(d>1){
                ans+="0";
                d--;
            }
        }
        for(int i=st.size()-2;i>=0;i--){
            ans+=st[i];
        }
        return ans;
    
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
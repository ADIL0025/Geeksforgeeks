//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int> freq(maxx + 2, 0); 

      
        for (int i = 0; i < n; i++) {
            freq[l[i]] += 1;
            freq[r[i] + 1] -= 1;
        }

        
        int maxFreq = freq[0], res = 0;
        for (int i = 1; i <= maxx; i++) {
            freq[i] += freq[i - 1];
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                res = i;
            }
        }

        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends
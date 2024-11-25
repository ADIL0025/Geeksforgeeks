//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        if(n==0){
            return 0;
        }
        int maxp = arr[0];
        int minp = arr[0];
        int proMax = arr[0];
        for(int i=1;i<n;i++){
            int temp = maxp;
            if(arr[i]<0){
                maxp = minp;
                minp = temp;
            }
            maxp = max(arr[i],maxp*arr[i]);
            minp = min(arr[i],minp*arr[i]);
            proMax = max(maxp,proMax);
        }
        return proMax;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
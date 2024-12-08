//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();  // Corrected syntax for array size
        sort(arr.begin(), arr.end());  // Sort intervals by their starting point
        vector<vector<int>> ans;  // Corrected declaration syntax with semicolon
        
        for (int i = 0; i < n; i++) {
            int start = arr[i][0];
            int end = arr[i][1];
            
            // Merge overlapping intervals
            while (i + 1 < n && arr[i + 1][0] <= end) {
                end = max(end, arr[i + 1][1]);
                i++;  // Move to the next interval
            }
            
            ans.push_back({start, end});  // Add the merged interval
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
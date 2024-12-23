//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int l=0, h=m*n - 1;
        
        while(l<=h){
            int mid = l + (h-l)/2;
            // (0, 3) => 3 => (3/4, 3%4)
            // (1, 2) => 6 => (6/4, 6%4)
            // (2, 1) => 9 => (9/4, 9%4)
            int row = mid/m;
            int col = mid%m;
            if(x==mat[row][col])
                return true;
            else if(x>mat[row][col])
                l=mid+1;
            else
                h=mid-1;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
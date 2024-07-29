//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
           int row= arr.size();
        int column = arr[0].size();
        int val=-1;
        int maxi=0;
        
        for(int i=0; i<row; i++){
            int count=0;
            for(int j=0; j<column; j++){
               if(arr[i][j]==1){
                   count++;
               } 
            if(count>maxi){
                   maxi= max(maxi, count);
                   val= i;
              }
            }
        }
        return val;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

   class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> p, n;
        int asize=arr.size();
        int pi = 0, ni = 0;
        for ( auto i : arr ) (i >= 0) ? p.push_back(i) : n.push_back(i);
        for ( int i = 0; i<asize; i++ ){
            if ( i%2 == 0 ){ 
                if ( ni < p.size() ) arr[i] = p[pi++];
                else arr[i] = n[ni++];
            } else {
                if ( ni < n.size() ) arr[i] = n[ni++];
                else arr[i] = p[pi++];
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
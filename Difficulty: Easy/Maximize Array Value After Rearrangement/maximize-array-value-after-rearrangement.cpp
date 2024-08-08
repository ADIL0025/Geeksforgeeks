//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  long long mod = 1e9+7;
    int Maximize(vector<int> arr) {
        // Complete the function
        int maxm = 0;
        int n = arr.size();
        sort(arr.begin(),arr.end() );
        for(long long i = 0;i<n;i++){
            long long res = (arr[i]*i)%mod;
            maxm = (maxm+res)%mod;
        }
        return (maxm%mod);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends
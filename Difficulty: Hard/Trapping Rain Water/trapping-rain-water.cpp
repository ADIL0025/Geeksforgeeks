//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
          vector<int> left, right;
        int n = arr.size();
        int maxi = arr[0];
        for(int i=0; i<n; i++){
            if(arr[i] > maxi) maxi = arr[i];
            left.push_back(maxi);
        }
        maxi = arr[n-1];
        for(int i=n-1; i>=0; i--){
            if(arr[i] > maxi) maxi = arr[i];
            right.push_back(maxi);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int count = min(left[i], right[n-1-i]) - arr[i];
            ans = ans+count;
        }
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
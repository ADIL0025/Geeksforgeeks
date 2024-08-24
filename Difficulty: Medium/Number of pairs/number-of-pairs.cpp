//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
        vector<float> crr(brr.size());
        for(int i=0;i<brr.size();i++){
            crr[i] = log(brr[i])/brr[i];
            // cout << crr[i] << " ";
        }
        // cout << endl;
        sort(crr.begin(),crr.end());
        long long ans =0;
        for(int i=0;i<arr.size();i++){
            // cout <<log(arr[i])/arr[i] << " ";
            float k = log(arr[i])/arr[i];
            ans += (lower_bound(crr.begin(),crr.end(),k)-crr.begin());
            // cout << k << endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
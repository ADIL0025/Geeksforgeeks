//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> solve(vector<int> &arr){
        
        vector<vector<int>> ans;
        unordered_map<int, vector<pair<int, int>>> mp;
        
        for (int i = 1; i < arr.size(); i++) {
            if (mp.count(-arr[i])) {
                for (auto &p : mp[-arr[i]]) {
                    vector<int> curr = {p.first, p.second, i};
                    ans.push_back(curr);
                }
            }
            for (int j = 0; j < i; j++) {
                mp[arr[i] + arr[j]].push_back({j, i});
            }
        }
        return ans;
    }
    vector<vector<int>> findTriplets(vector<int> &arr) {
        return solve(arr);
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        unordered_set<int>s;
        int n=arr.size();
        int max_num=1;
        for(int i=0;i<n;i++){
            max_num=max(max_num,arr[i]);
            s.insert(arr[i]);
        }
        for(int i=1;i<=max_num+1;i++){
            if(s.find(i)==s.end()){
                return i;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends
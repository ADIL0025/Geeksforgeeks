//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) 
    {
        // Sort the array to bring the strings with the smallest and largest lexicographic order next to each other
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        // Determine the length of the smallest string between the first and last string in the sorted array
        int len = min(arr[0].length(), arr[n-1].length());
        
        int i = 0;
        string str = "";
        
        // Compare characters of the first and last strings in the sorted array to find the common prefix
        while(i < len && arr[0][i] == arr[n-1][i])
        {
            str = str + arr[0][i];
            i++;
        }
        
        // Return "-1" if no common prefix is found, otherwise return the common prefix
        if(str == "")
            return "-1";
        return str;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends